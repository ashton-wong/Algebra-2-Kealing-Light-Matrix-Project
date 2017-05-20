import numpy as np
import picamera
import picamera.array
from picamera.array import PiMotionAnalysis
from PIL import Image
import os
import time

#Used for video creation
#import cv2

#The bulk of the analysis goes here!
class EntityCapture(PiMotionAnalysis):

    def __init__(self, camera):
        super(EntityCapture, self).__init__(camera)
        self.frame_num = 0

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

        #So this is just magnitude of change (distance) turned into a
        #picture! NOT WHAT WE WANT!
        #data = np.sqrt(
                #np.square(a['x'].astype(np.float)) +
                #np.square(a['y'].astype(np.float))
                #).clip(0, 255).astype(np.uint8)
        #img = Image.fromarray(data)
        

        #Frame metadata
        filename = 'frame%03d.png' % self.frame_num
        print(filename)

        #Debug
        #print(data.shape[0])
        #print(data.shape[1]-1)
        #print(a['x'])
        #print(a['y'])
        
        x = np.where(a['x'] != 0)
        print(x)
        
        y = np.where(a['y'] != 0)
        print(y)                
            
        #Save frames
        #img.save(filename)
        self.frame_num += 1

        #Straight to a video
        # #'s next 3 lines
        #self.video.write(cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR))

    def finish(self):
        self.video.release()

#This part must go at the end.
#Keeps the program going...until Ctrl-C
with picamera.PiCamera(resolution='VGA', framerate=24) as camera:
    with EntityCapture(camera) as detector:
        camera.rotation = 180

        print("Warming up...")
        time.sleep(2)

        print("3")
        time.sleep(0.5)
        print("2")
        time.sleep(0.5)
        print("1")
        time.sleep(0.5)

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
            #detector.finish()
