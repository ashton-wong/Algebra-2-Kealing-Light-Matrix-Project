import numpy as np
import picamera
import picamera.array
from picamera.array import PiMotionAnalysis
from PIL import Image
import os
import time

#The bulk of the analysis goes here!
class EntityCapture(PiMotionAnalysis):
    #QUEUE_SIZE = 10 # the number of consecutive frames to analyze
    #THRESHOLD = 1.0 # the minimum average motion required in either axis

    def __init__(self, camera):
        super(EntityCapture, self).__init__(camera)
        self.frame_num = 0
        #self.x_queue = np.zeros(self.QUEUE_SIZE, dtype=np.float)
        #self.y_queue = np.zeros(self.QUEUE_SIZE, dtype=np.float)

    def analyze(self, a):
        data = np.sqrt(
                np.square(a['x'].astype(np.float)) +
                np.square(a['y'].astype(np.float))
                ).clip(0, 255).astype(np.uint8)
        img = Image.fromarray(data)

        #Save frame images
        #filename = 'frame' + str(self.frame_num) + '.png'
        #print('Writing', filename)
        #img.save(filename)
        #self.frame_num += 1

        #Display to screen (not quite working)
        img.show()
    
        # Roll the queues and overwrite the first element with a new
        # mean (equivalent to pop and append, but faster)
        #self.x_queue[1:] = self.x_queue[:-1]
        #self.y_queue[1:] = self.y_queue[:-1]
        #self.x_queue[0] = a['x'].mean()
        #self.y_queue[0] = a['y'].mean()
        # Calculate the mean of both queues
        #x_mean = self.x_queue.mean()
        #y_mean = self.y_queue.mean()
        # Convert left/up to -1, right/down to 1, and movement below
        # the threshold to 0
        #if abs(x_mean) < self.THRESHOLD:
        #    x_move = ''
        #elif x_mean < 0.0:


#This part must go at the end.
#Keeps the program going...until Ctrl-C
with picamera.PiCamera(resolution='VGA', framerate=24) as camera:
    with EntityCapture(camera) as detector:
        camera.rotation = 180
        
        time.sleep(2)

        camera.start_recording(
            os.devnull, format='h264', motion_output=detector)
        #camera.start_preview()
        
        try:
            while True:
                camera.wait_recording(1)
        except KeyboardInterrupt:
            pass
        finally:
            camera.stop_recording()
