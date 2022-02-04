from PIL import Image
from tqdm import tqdm

IMAGE = Image.open("./boat.jpg")

# labImg = Image.fromarray(numpy.asarray(IMAGE), mode="LAB")
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
            pixelS = IMAGE.getpixel((row, col + 1))
            pixelSE = IMAGE.getpixel((row + 1, col + 1))
            pixelE = IMAGE.getpixel((row + 1, col))
        elif row == (IMAGE.size[0] - 1) and col == 0:
            # top right corner
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelSW = IMAGE.getpixel((row - 1, col + 1))
            pixelS = IMAGE.getpixel((row, col + 1))
        elif col == (IMAGE.size[1] - 1) and row == (IMAGE.size[0] - 1):
            # bottom right corner
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelNW = IMAGE.getpixel((row - 1, col - 1))
            pixelN = IMAGE.getpixel((row, col - 1))
        elif col == (IMAGE.size[1] - 1) and row == 0:
            # bottom left corner
            pixelN = IMAGE.getpixel((row, col - 1))
            pixelNE = IMAGE.getpixel((row + 1, col - 1))
            pixelE = IMAGE.getpixel((row + 1, col))
        elif col == 0:
            # first row
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelSW = IMAGE.getpixel((row - 1, col + 1))
            pixelS = IMAGE.getpixel((row, col + 1))
            pixelSE = IMAGE.getpixel((row + 1, col + 1))
            pixelE = IMAGE.getpixel((row + 1, col))
        elif row == 0:
            # first col
            pixelS = IMAGE.getpixel((row, col + 1))
            pixelSE = IMAGE.getpixel((row + 1, col + 1))
            pixelE = IMAGE.getpixel((row + 1, col))
            pixelNE = IMAGE.getpixel((row + 1, col - 1))
            pixelN = IMAGE.getpixel((row, col - 1))
        elif col == (IMAGE.size[1] - 1):
            # last row
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelNW = IMAGE.getpixel((row - 1, col - 1))
            pixelN = IMAGE.getpixel((row, col- 1))
            pixelNE = IMAGE.getpixel((row + 1, col - 1))
            pixelE = IMAGE.getpixel((row + 1, col))
        elif row == (IMAGE.size[0] - 1):
            # last column
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelSW = IMAGE.getpixel((row - 1, col + 1))
            pixelS = IMAGE.getpixel((row, col + 1))
            pixelN = IMAGE.getpixel((row, col - 1))
            pixelNW = IMAGE.getpixel((row - 1, col - 1))
        else:
            pixelW = IMAGE.getpixel((row - 1, col))
            pixelSW = IMAGE.getpixel((row - 1, col + 1))
            pixelS = IMAGE.getpixel((row, col + 1))
            pixelSE = IMAGE.getpixel((row + 1, col + 1))
            pixelE = IMAGE.getpixel((row + 1, col))
            pixelNE = IMAGE.getpixel((row + 1, col - 1))
            pixelN = IMAGE.getpixel((row, col - 1))
            pixelNW = IMAGE.getpixel((row - 1, col - 1))
            pixelSE = IMAGE.getpixel((row + 1, col + 1))

        redNeighbor = ((pixelN[0] + pixelNE[0] + pixelE[0] + pixelSE[0] + pixelS[0] + pixelSW[0] + pixelW[0] + pixelNW[0])/8)
        greenNeighbor = ((pixelN[1] + pixelNE[1] + pixelE[1] + pixelSE[1] + pixelS[1] + pixelSW[1] + pixelW[1] + pixelNW[1])/8)
        blueNeighbor = ((pixelN[2] + pixelNE[2] + pixelE[2] + pixelSE[2] + pixelS[2] + pixelSW[2] + pixelW[2] + pixelNW[2])/8)

        pixel = IMAGE.getpixel((row, col))
        distance = abs(pixel[0] - redNeighbor) + abs(pixel[1] - greenNeighbor) + abs(pixel[2] - blueNeighbor)

        # distance = math.sqrt(abs(pixel[0] - redNeighbor)**2 + abs(pixel[1] - greenNeighbor)**2 + abs(pixel[2] - blueNeighbor)**2)

        if distance > 30:
            edgePx[row, col] = (0, 0, 0)
        else:
            edgePx[row, col] = (255, 255, 255)

edgeImage.show()
