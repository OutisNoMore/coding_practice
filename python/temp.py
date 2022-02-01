import math
import matplotlib.pyplot
import numpy
from PIL import Image
from tqdm import tqdm

IMAGE = Image.open("./lake.jpg")
PIXEL_MAP = IMAGE.load()
"""
# apply blue filter on image
for row in tqdm(range(IMAGE.size[0])):
    for col in range(IMAGE.size[1]):
        pixel = list(PIXEL_MAP[row, col])  # tuple (r, g, b) of pixel at index row, col
        blueVal = int(pixel[1] * 1.3) # apply blue filter
        if blueVal > 255:
            # ensure that blue won't exceed 255
            blueVal = 255
        pixel[2] = blueVal
        PIXEL_MAP[row, col] = tuple(pixel)
#  rotate image by 90 degrees counter-clockwise
im_flipped = Image.new("RGB", (IMAGE.height, IMAGE.width))
flipPx = im_flipped.load()

for x in tqdm(range(IMAGE.size[0])):
    for y in range(IMAGE.size[1]):
        pixel = PIXEL_MAP[x, y]
        flipPx[IMAGE.size[1] - y - 1, x] = pixel

matplotlib.pyplot.imshow(im_flipped)
matplotlib.pyplot.show()

# create four small versions of the image
im_small = IMAGE.resize((IMAGE.width // 2, IMAGE.height // 2))
im_four = Image.new('RGB', (IMAGE.width, IMAGE.height))

im_four.paste(im_small, (0, 0)) # top left
im_four.paste(im_small, (im_small.width, 0)) # top right
im_four.paste(im_small, (0, im_small.height)) # bottom left
im_four.paste(im_small, (im_small.width, im_small.height)) # bottom right
"""
# enlarge picture
im_large = Image.new('RGB', (IMAGE.width * 2, IMAGE.height * 2))
im_large_px = im_large.load()
largeRow = 0
largeCol = 0
for row in tqdm(range(IMAGE.size[0])):
    for col in range(IMAGE.size[1]):
        if largeCol == im_large.size[1]:
            largeCol = 0
            largeRow = largeRow + 2

        pixel = PIXEL_MAP[row, col]
        im_large_px[row*2, col*2] = pixel
        im_large_px[row*2, col*2 + 1] = pixel
        im_large_px[row*2 + 1, col*2] = pixel
        im_large_px[row*2 + 1, col*2 + 1] = pixel
        largeCol = largeCol + 2

matplotlib.pyplot.imshow(im_large)
matplotlib.pyplot.show()

"""
# apply gray filter on image
for row in tqdm(range(IMAGE.size[0])):
    for col in range(IMAGE.size[1]):
        pixel = PIXEL_MAP[row, col]  # tuple (r, g, b) of pixel at index row, col
        grayLevel = 0.2126 * pixel[0] + 0.7152 * pixel[1]+ 0.0722 * pixel[2]
        grayLevel = int(grayLevel)
        PIXEL_MAP[row, col] = (grayLevel, grayLevel, grayLevel)

# edge detection 
for row in tqdm(range(IMAGE.size[0])):
    for col in range(IMAGE.size[1]):
        pixel = PIXEL_MAP[row, col]  # tuple (r, g, b) of pixel at index row, col
        pixelSouth = (0, 0, 0)
        pixelEast = (0, 0, 0)
        pixelSE = (0, 0, 0)
        if col == (IMAGE.size[1] - 1) and row == (IMAGE.size[0] - 1):
            continue
        elif col == (IMAGE.size[1] - 1):
            pixelSouth = PIXEL_MAP[row + 1, col]
        elif row == (IMAGE.size[0] - 1):
            pixelEast = PIXEL_MAP[row, col + 1]
        else:
            pixelEast = PIXEL_MAP[row, col + 1]
            pixelSouth = PIXEL_MAP[row + 1, col]
            pixelSE = PIXEL_MAP[row + 1, col + 1]

        redNeighbor = ((pixelSouth[0] + pixelEast[0] + pixelSE[0])/3)
        greenNeighbor = ((pixelSouth[1] + pixelEast[1] + pixelSE[1])/3)
        blueNeighbor = ((pixelSouth[2] + pixelEast[2] + pixelSE[2])/3)
        distance = math.sqrt(abs(pixel[0] - redNeighbor) ** 2 + abs(pixel[1] - greenNeighbor) ** 2 + abs(pixel[2] - blueNeighbor) ** 2)

        if distance > 20:
            PIXEL_MAP[row, col] = (0, 0, 0)
        else:
            PIXEL_MAP[row, col] = (255, 255, 255)

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
            pixelE = PIXEL_MAP[row, col + 1]
            pixelSE = PIXEL_MAP[row + 1, col + 1]
            pixelS = PIXEL_MAP[row + 1, col]
        elif row == (IMAGE.size[0] - 1) and col == 0:
            # bottom left corner
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNE = PIXEL_MAP[row - 1, col + 1]
            pixelE = PIXEL_MAP[row, col + 1]
        elif col == (IMAGE.size[1] - 1) and row == (IMAGE.size[0] - 1):
            # bottom right corner
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNW = PIXEL_MAP[row - 1, col - 1]
            pixelW = PIXEL_MAP[row, col - 1]
        elif col == (IMAGE.size[1] - 1) and row == 0:
            # top right corner
            pixelW = PIXEL_MAP[row, col - 1]
            pixelSW = PIXEL_MAP[row + 1, col - 1]
            pixelS = PIXEL_MAP[row + 1, col]
        elif col == 0:
            # first column
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNE = PIXEL_MAP[row - 1, col + 1]
            pixelE = PIXEL_MAP[row, col + 1]
            pixelSE = PIXEL_MAP[row + 1, col + 1]
            pixelS = PIXEL_MAP[row + 1, col]
        elif row == 0:
            # first row
            pixelE = PIXEL_MAP[row, col + 1]
            pixelSE = PIXEL_MAP[row + 1, col + 1]
            pixelS = PIXEL_MAP[row + 1, col]
            pixelSW = PIXEL_MAP[row + 1, col - 1]
            pixelW = PIXEL_MAP[row, col - 1]
        elif col == (IMAGE.size[1] - 1):
            # last column
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNW = PIXEL_MAP[row - 1, col - 1]
            pixelW = PIXEL_MAP[row, col- 1]
            pixelSW = PIXEL_MAP[row + 1, col - 1]
            pixelS = PIXEL_MAP[row + 1, col]
        elif row == (IMAGE.size[0] - 1):
            # last row
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNE = PIXEL_MAP[row - 1, col + 1]
            pixelE = PIXEL_MAP[row, col + 1]
            pixelW = PIXEL_MAP[row, col - 1]
            pixelNW = PIXEL_MAP[row - 1, col - 1]
        else:
            pixelN = PIXEL_MAP[row - 1, col]
            pixelNE = PIXEL_MAP[row - 1, col + 1]
            pixelE = PIXEL_MAP[row, col + 1]
            pixelSE = PIXEL_MAP[row + 1, col + 1]
            pixelS = PIXEL_MAP[row + 1, col]
            pixelSW = PIXEL_MAP[row + 1, col - 1]
            pixelW = PIXEL_MAP[row, col - 1]
            pixelNW = PIXEL_MAP[row - 1, col - 1]
            pixelSE = PIXEL_MAP[row + 1, col + 1]

        redNeighbor = ((pixelN[0] + pixelNE[0] + pixelE[0] + pixelSE[0] + pixelS[0] + pixelSW[0] + pixelW[0] + pixelNW[0])/8)
        greenNeighbor = ((pixelN[1] + pixelNE[1] + pixelE[1] + pixelSE[1] + pixelS[1] + pixelSW[1] + pixelW[1] + pixelNW[1])/8)

        blueNeighbor = ((pixelN[2] + pixelNE[2] + pixelE[2] + pixelSE[2] + pixelS[2] + pixelSW[2] + pixelW[2] + pixelNW[2])/8)

        distance = abs(pixel[0] - redNeighbor) + abs(pixel[1] - greenNeighbor) + abs(pixel[2] - blueNeighbor)

        if distance > 30:
            edgePx[row, col] = (0, 0, 0)
        else:
            edgePx[row, col] = (255, 255, 255)

matplotlib.pyplot.imshow(IMAGE)
matplotlib.pyplot.show()
"""
