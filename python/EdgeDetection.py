import picamera
import numpy as np
from picamera.array import PiRGBAnalysis
from picamera.color import Color

# import math for the square root function
import math


class MyColorAnalyzer(PiRGBAnalysis):
    def __init__(self, camera):
        super(MyColorAnalyzer, self).__init__(camera)
        self.last_color = ''

    def analyze(self, img):
        img_edge = Image(640, 480)
        # iterate over each pixel in the image: the Sobel Operator itself
        for x in range(1, img.width - 1):
                for y in range(1, img.height - 1):
                        # initialize Gx to 0 and Gy to 0 for every pixel
                        Gx = 0
                        Gy = 0


                        # top left pixel
                        r, g, b = img[x - 1, y - 1]
                        # intensity ranges from 0 to 765 (255 * 3)
                        intensity = (r + g + b)
                        # accumulate the value into Gx, and Gy
                        Gx += -intensity
                        Gy += -intensity


                        # now we do the same for the remaining pixels, left to right, top to bottom


                        # remaining left column
                        r, g, b = img[x - 1, y]
                        Gx += -2 * (r + g + b)

                        r, g, b = img[x - 1, y + 1]
                        Gx += -(r + g + b)
                        Gy += (r + g + b)


                        # middle pixels
                        r, g, b = img[x, y - 1]
                        Gy += -2 * (r + g + b)

                        r, g, b = img[x, y + 1]
                        Gy += 2 * (r + g + b)


                        # right column
                        r, g, b = img[x + 1, y - 1]
                        Gx += (r + g + b)
                        Gy += -(r + g + b)

                        r, g, b = img[x + 1, y]
                        Gx += 2 * (r + g + b)

                        r, g, b= img[x + 1, y + 1]
                        Gx += (r + g + b)
                        Gy += (r + g + b)


                        # calculate the length of the gradient
                        length = math.sqrt((Gx * Gx) + (Gy * Gy))

                        # normalize the length of gradient to the range 0 to 255
                        length = length / 4328 * 255

                        # convert the length to an integer
                        length = int(length)

                        # draw the length in the edge image
                        img_edge[x, y] = length, length, length


with picamera.PiCamera(resolution='640x480', framerate=24) as camera:
    with MyColorAnalyzer(camera) as analyzer:
        camera.start_recording(analyzer, 'rgb')
        try:
            while True:
                camera.wait_recording(1)
        finally:
            camera.stop_recording()


# end script
