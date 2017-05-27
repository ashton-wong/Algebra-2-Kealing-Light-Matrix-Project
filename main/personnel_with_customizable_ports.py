import numpy as np
import picamera
import picamera.array
from picamera.array import PiMotionAnalysis
from PIL import Image
import os
import time
import serial

#Used for video creation
#import cv2

#The bulk of the analysis goes here!
class EntityCapture(PiMotionAnalysis):

    def __init__(self, camera):
        super(EntityCapture, self).__init__(camera)

        #If anyone has time and wants to figure this out, go ahead
        #Creates a video file called test with whatever codec chosen
        #You will have to rename the video with the right extension
        #self.video = cv2.VideoWriter("test.mp4", -1, 24, (640, 480))

    def analyze(self, a):
        #Distance formula :)
        #The big part of finishing our goal for this aspect:
        #Figure out exactly what data is storing
        #Make a new array or change data so that it shows
        #what's in front of the camera

        #print(a['x'].shape)
        #print(a['x'])
        
        #print(a['y'].shape)
        #print(a['y'])

        #print(a['sad'].shape)
        #print(a['sad'])

        magnitude = np.sqrt(
                np.square(a['x'].astype(np.float)) +
                np.square(a['y'].astype(np.float))
                ).astype(np.uint8)

        #Debug
        #print(data.shape[0])
        #print(data.shape[1]-1)
        #print(a['x'])
        #print(a['y'])

        #print(magnitude.shape)

        column_indexes, row_indexes = np.where(magnitude > 0)

        #Numpy array indexes start at top left, advance through
        # 4th quadrant

        #filename = 'frame%03d.png' % self.frame_num
        #print(filename)
        #print(magnitude.shape)
        #print(row_indexes)
        #print(column_indexes)
        
        max_vals = np.zeros(26, dtype=np.uint8)

        for current in range(column_indexes.shape[0]):
            row_index = row_indexes[current]
            column_index = column_indexes[current]
            #print("-------------------")
            #print(row_index)
            #print(column_index)
            #print("-------------------")
            if max_vals[column_index] < row_index:
                max_vals[column_index] = row_index
            #print(max_vals)
            #ser1.write(chr(x_index[index]))
            #ser1.write(chr(y_index[index]))
            #ser2.write(chr(x_index[index]))
            #ser2.write(chr(y_index[index]))
            
        left, mid, right = np.split(max_vals, [10, 16])
        #print(left)
        #print(mid)
        #print(right)
        #print('--------------------------------------')
        #print(max_vals)
        #print(left)
        #print(mid)
        #print(right)

        #Send stuff over
        #for element in range(mid.shape[0]):
        #    ser1.write(chr(mid[element]))
        #for element in range(right.shape[0]):
        #    ser2.write(chr(right[element]))
        #for element in range(left.shape[0]):
        #    ser3.write(chr(left[element]))
        if serialon:
            for element in range(left.shape[0]):
                #Exception handlers are slow, can use optimization FIXME!
                try:
                    ser_mid.write(chr(mid[element]))
                except IndexError:
                    ser_mid.write(chr(0))
                finally:
                    ser_left.write(chr(right[element]))
                    ser_right.write(chr(left[element]))

        #Flag for execution
        #ser1.write(chr(72))
        #ser2.write(chr(72))
        #ser3.write(chr(72))

        #End of new stuff
        
        #for i in range(magnitude.shape[0]):
            #for j in range(magnitude.shape[1]):
                #if magnitude[i][j] != 0:
                    #self.persist[i][j] = 1
                    #value_x = a[i][j][0]
                    #value_y = a[i][j][1]
                    #prev_x = i - int(value_x / 16)
                    #prev_y = j - int(value_y / 16)
                    #if (prev_x < 30) and (prev_y < 41) and (prev_x >= 0) and (prev_y >= 0):
                        #self.persist[prev_x][prev_y] = 0
                    #else:
                        #print("Out of bounds:", prev_x, prev_y)

        #if x_index != []:
        #    cur_index = 0
        #    for i in np.nditer(x_index):
        #        j = y_index[cur_index]
        #        value_x = a[i][j][0]
        #        value_y = a[i][j][1]
                #print("x index:", i)
                #print("x value:", value_x)
                #print("x block:", int(value_x / 16))
                #print("y index:", j)
                #print("y value:", value_y)
                #print("y block:", int(value_y / 16))
                #print("--------------------------")
                #self.persist[i][j] = magnitude[i][j]
                #try:
                #    self.persist[i + int(value_x / 16)][j + int(value_y / 16)] = 0
                #except IndexError:
                #    self.boundfail += 1
                #cur_index += 1

        #h, i = np.where(a['x'] != 0)
        #v_x = a['x'][h][i]
        #print(h, v_x)
        
        #j, k = np.where(a['y'] != 0)
        #v_y = a['y'][j][k]
        #print(k, v_y)

        #Frame metadata
        #print(x_index)
        #print(y_index)

        #viewable = np.multiply(self.persist, 255)

        #img = Image.fromarray(viewable.clip(0, 255).astype(np.uint8))

        #for i in range(self.persist.shape[0]):
            #for j in range(self.persist.shape[1]):
                #if self.persist[i][j] == 1:
                    #print("1", end='')
                #else:
                    #print("0", end='')
            #print()ser = serial.Serial('/dev/ttyACM0', 115200)
        #print("-----------------------------------------------------------")
        #print(self.persist.shape[0], self.persist.shape[1])
        
        #print(viewable)
        #print(magnitude)
        #print(self.persist)
                
        #Save frames
        #img.save(filename)
        #self.frame_num += 1

        #Straight to a video
        # #'s next 3 lines
        #self.video.write(cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR))

    def finish(self):
                                    
        self.video.release()

#This part must go at the end.
#Keeps the program going...until Ctrl-C
with picamera.PiCamera(resolution=(720, 416)) as camera:
    with EntityCapture(camera) as detector:

        serialon = True;
        prev_on = True;

        #Ask about ports
        left_num = str(input("What is the port number for the left panel? "))
        mid_num = str(input("Middle panel? "))
        right_num = str(input("Right panel? "))

        #Convert to right string
        left = '/dev/ttyACM' + left_num
        mid = '/dev/ttyACM' + mid_num
        right = '/dev/ttyACM' + right_num
        
        camera.hflip = True;
        print("Warming up...")
        time.sleep(1)
        print("Enjoy your cascade!")
        time.sleep(1)
        print(":)")
        if serialon:
            ser_left = serial.Serial(left, 115200)
            ser_mid = serial.Serial(mid, 115200)
            ser_right = serial.Serial(right, 115200)
        time.sleep(2)

        print("3")
        time.sleep(0.5)
        print("2")
        time.sleep(0.5)
        print("1")
        time.sleep(0.5)

        if prev_on:
            camera.start_preview()
            camera.preview.alpha = 150

        camera.start_recording(
            os.devnull, format='h264', motion_output=detector)
        #delete the hashtag below later
        #camera.start_preview()
        
        try:
            while True:
                camera.wait_recording(1)
        except KeyboardInterrupt:
            pass
        finally:
            camera.stop_recording()
            if prev_on:
                camera.stop_preview()
            #print("Out of ranges:", detector.boundfail)
            #detector.finish()
