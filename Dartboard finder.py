import cv2
import numpy as np
import time
import serial

# Open serial port (check the COM port on system)
ser = serial.Serial('COM6', 9600)  # Windows example

# Start video capture from the default webcam (0)
cap = cv2.VideoCapture(0)

x_res = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
y_res = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

x_mid = int(x_res/2)
y_mid = int(y_res/2)

def get_direction(x, y):
    if x > (x_mid + 10): #turn right
        print("R")
        return 82
    elif x < (x_mid - 10): #turn left
        print("L")
        return 76
    elif y > (y_mid + 10): #tilt down
        print("D")
        return 68
    elif y < (y_mid - 10): #tilt up
        print("U")
        return 85
    else:
        print("C")
        return 67

if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()  

while True:
    # Read a frame from the webcam
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to read frame.")
        break

    # Convert frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian blur to reduce noise and improve circle detection
    blurred = cv2.GaussianBlur(gray, (15, 15), 0)

    # Use Hough Circle Transform to detect circles
    circles = cv2.HoughCircles(blurred, 
                               cv2.HOUGH_GRADIENT, dp=1, minDist=10000, 
                               param1=50, param2=40, minRadius=10, maxRadius=100)

    # If circles are found, draw them on the frame
    
    if circles is not None:
        circles = np.round(circles[0, :]).astype("int")
        for (x, y, r) in circles:
            # Draw the circle center
            cv2.circle(frame, (x, y), 3, (0, 255, 0), 5)
            # Draw the circumference of the circle
            cv2.circle(frame, (x, y), r, (0, 0, 255), 3)
            
            ser.write(bytes([get_direction(x,y)]))

    # Show the live frame with detected circles
    cv2.imshow("Circle Detection", frame)

    # Press 'q' to quit
    if cv2.waitKey(1) == ord('q'):
        break
    #time.sleep(0.5)
# Release the webcam and close windows
ser.close()
cap.release()
cv2.destroyAllWindows()