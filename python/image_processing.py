import math
import matplotlib.pyplot
import numpy
from PIL import Image
from tqdm import tqdm

IMAGE = Image.open("./lake.jpg")

labImg = Image.fromarray(numpy.asarray(IMAGE), mode="LAB")
edgeImage = Image.new('RGB', (IMAGE.width, IMAGE.height))
edgePx = edgeImage.load()

for row in tqdm(range(IMAGE.size[0])):
    for col in range(IMAGE.size[1]):
        pixelN = (0, 0, 0)
        pixelNE = (0, 0, 0)
        pixelE = (0, 0, 0)
        pixelSE = (0, 0, 0)
        pixelS = (0, 0, 0)
        pixelSW = (0, 0, 0)
        pixelW = (0, 0, 0)
        pixelNW = (0, 0, 0)

        if row == 0 and col == 0:
            # top left corner
            pixelE = labImg.getpixel((row, col + 1))
            pixelSE = labImg.getpixel((row + 1, col + 1))
            pixelS = labImg.getpixel((row + 1, col))
        elif row == (IMAGE.size[0] - 1) and col == 0:
            # bottom left corner
            pixelN = labImg.getpixel((row - 1, col))
            pixelNE = labImg.getpixel((row - 1, col + 1))
            pixelE = labImg.getpixel((row, col + 1))
        elif col == (IMAGE.size[1] - 1) and row == (IMAGE.size[0] - 1):
            # bottom right corner
            pixelN = labImg.getpixel((row - 1, col))
            pixelNW = labImg.getpixel((row - 1, col - 1))
            pixelW = labImg.getpixel((row, col - 1))
        elif col == (IMAGE.size[1] - 1) and row == 0:
            # top right corner
            pixelW = labImg.getpixel((row, col - 1))
            pixelSW = labImg.getpixel((row + 1, col - 1))
            pixelS = labImg.getpixel((row + 1, col))
        elif col == 0:
            # first column
            pixelN = labImg.getpixel((row - 1, col))
            pixelNE = labImg.getpixel((row - 1, col + 1))
            pixelE = labImg.getpixel((row, col + 1))
            pixelSE = labImg.getpixel((row + 1, col + 1))
            pixelS = labImg.getpixel((row + 1, col))
        elif row == 0:
            # first row
            pixelE = labImg.getpixel((row, col + 1))
            pixelSE = labImg.getpixel((row + 1, col + 1))
            pixelS = labImg.getpixel((row + 1, col))
            pixelSW = labImg.getpixel((row + 1, col - 1))
            pixelW = labImg.getpixel((row, col - 1))
        elif col == (IMAGE.size[1] - 1):
            # last column
            pixelN = labImg.getpixel((row - 1, col))
            pixelNW = labImg.getpixel((row - 1, col - 1))
            pixelW = labImg.getpixel((row, col- 1))
            pixelSW = labImg.getpixel((row + 1, col - 1))
            pixelS = labImg.getpixel((row + 1, col))
        elif row == (IMAGE.size[0] - 1):
            # last row
            pixelN = labImg.getpixel((row - 1, col))
            pixelNE = labImg.getpixel((row - 1, col + 1))
            pixelE = labImg.getpixel((row, col + 1))
            pixelW = labImg.getpixel((row, col - 1))
            pixelNW = labImg.getpixel((row - 1, col - 1))
        else:
            pixelN = labImg.getpixel((row - 1, col))
            pixelNE = labImg.getpixel((row - 1, col + 1))
            pixelE = labImg.getpixel((row, col + 1))
            pixelSE = labImg.getpixel((row + 1, col + 1))
            pixelS = labImg.getpixel((row + 1, col))
            pixelSW = labImg.getpixel((row + 1, col - 1))
            pixelW = labImg.getpixel((row, col - 1))
            pixelNW = labImg.getpixel((row - 1, col - 1))
            pixelSE = labImg.getpixel((row + 1, col + 1))

        redNeighbor = ((pixelN[0] + pixelNE[0] + pixelE[0] + pixelSE[0] + pixelS[0] + pixelSW[0] + pixelW[0] + pixelNW[0])/8)
        greenNeighbor = ((pixelN[1] + pixelNE[1] + pixelE[1] + pixelSE[1] + pixelS[1] + pixelSW[1] + pixelW[1] + pixelNW[1])/8)
        blueNeighbor = ((pixelN[2] + pixelNE[2] + pixelE[2] + pixelSE[2] + pixelS[2] + pixelSW[2] + pixelW[2] + pixelNW[2])/8)

        pixel = labImg.getpixel((row, col))
        distance = math.sqrt(abs(pixel[0] - redNeighbor)**2 + abs(pixel[1] - greenNeighbor)**2 + abs(pixel[2] - blueNeighbor)**2)

        if distance > 2.3:
            edgePx[row, col] = (0, 0, 0)
        else:
            edgePx[row, col] = (255, 255, 255)

matplotlib.pyplot.imshow(edgeImage)
matplotlib.pyplot.show()
