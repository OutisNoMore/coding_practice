"""
Author: Jaemok C. Lee
Date: 02/03/2022
Lab 4
----------------------------------------------------------------------------
Academic Honesty Pledge
    I, Jaemok Lee, do hereby certify that I have derived no assistance for
    this project or examination from any sources whatsoever, whether oral,
    written, or in print.
----------------------------------------------------------------------------
Program Description
    This program is a image processing toolkit that allows the user to 
    edit an image with different functions.
----------------------------------------------------------------------------
INPUT
   Path to a jpg image
----------------------------------------------------------------------------
OUTPUT
    Display edited or original image to screen
    Save edited image
----------------------------------------------------------------------------
References
    https://www.tutorialspoint.com/python/string_endswith.htm
"""
from PIL import Image

def createNegative(image):
    """Takes the passed image and returns a negative copy"""
    px = image.load()
    newImage = Image.new("RGB", (image.width, image.height))
    newPx = newImage.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            pixel = px[x, y]
            # invert each pixel by subtracting from 255
            red = 255 - pixel[0]
            green = 255 - pixel[1]
            blue = 255 - pixel[2]
            # set pixel of newImage to the inverted values
            newPx[x, y] = (red, green, blue)
    # return copy of negative image 
    return newImage

def adjustBrightness(image, level):
    """Takes the passed image and returns a copy adjusted by given brightness level"""
    newImage = Image.new("RGB", (image.width, image.height))
    newPx = newImage.load()
    px = image.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            pixel = px[x, y]
            # adjust brightness of each rgb value
            red = int(pixel[0] * (1 + level))
            green = int(pixel[1] * (1 + level))
            blue = int(pixel[2] * (1 + level))
            # ensure that each value does not exceed maximum value: 255
            if red > 255:
                red = 255
            if green > 255:
                green = 255
            if blue > 255:
                blue = 255
            # set pixel of newImage to adjusted values
            newPx[x, y] = (red, green, blue)
    # return copy of brightness adjusted image
    return newImage

def flipVertically(image):
    """Takes the passed image and returns a copy flipped vertically"""
    newImage = Image.new("RGB", (image.width, image.height))
    newPx = newImage.load()
    px = image.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            # copy pixel to vertical opposite
            newPx[x, image.height - 1 - y] = px[x, y]
    # return copy of vertically flipped image
    return newImage

def flipHorizontally(image):
    """Takes the passed image and returns a copy flipped horizontally"""
    newImage = Image.new("RGB", (image.width, image.height))
    newPx = newImage.load()
    px = image.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            # copy pixel to horizontal opposite
            newPx[image.width - x - 1, y] = px[x, y]
    # return copy of horizontally flipped image
    return newImage

def rotateLeft(image):
    """Takes the given image and returns a copy rotated counter clockwise by 90 degrees"""
    newImage = Image.new("RGB", (image.height, image.width))
    newPx = newImage.load()
    px = image.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            # copy pixel to the corresponding value
            newPx[y, image.width - 1 - x] = px[x, y]
    # return copy of rotated image
    return newImage

def findEdges(image, threshold):
    """Takes the given image and returns a copy with the edges detected"""
    newImage = Image.new("RGB", (image.width, image.height)) 
    newPx = newImage.load()
    px = image.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            # keep track of RGB of three neighboring pixels
            neighborEast = (0, 0, 0)
            neighborSE = (0, 0, 0)
            neighborSouth = (0, 0, 0)

            # East = to the right (x + 1, y)
            # South = Below (x, y + 1)
            # South East = bottom right (x + 1, y + 1)
            # edge cases = last column and last row - No neighbors
            #              last column - Only South
            #              last row    - Only East

            if x == (image.width - 1) and y == (image.height - 1):
                # Check if last column and last Row
                continue # no neighbors
            elif x == (image.width - 1):
                # Check if last column - only South neighbor
                neighborSouth = px[x, y + 1]
            elif y == (image.height - 1):
                # Check if last row - only East neighbor
                neighborEast = px[x + 1, y]
            else:
                # otherwise all neighbors
                # South Neighbors
                neighborSouth = px[x, y + 1]
                # East Neighbors
                neighborEast = px[x + 1, y]
                # South East Neighbors
                neighborSE = px[x + 1, y + 1]
      
                # average rgb all three neighbors
                redNeighbor = (neighborEast[0] + neighborSE[0] + neighborSouth[0]) / 3
                greenNeighbor = (neighborEast[1] + neighborSE[1] + neighborSouth[1]) / 3
                blueNeighbor = (neighborEast[2] + neighborSE[2] + neighborSouth[2]) / 3
                # calculate distance/how different the rgb of pixel against its neighbor
                distance = abs(px[x, y][0] - redNeighbor)**2 + abs(px[x, y][1] - greenNeighbor)**2 + abs(px[x, y][2] - blueNeighbor)**2
                distance = distance ** 0.5
            if distance > threshold:
                newPx[x, y] = (0, 0, 0)
            else:
                newPx[x, y] = (255, 255, 255)
    # return copy of edge detected image
    return newImage

def createGrayscale(image):
    """Takes the given image and returns a grayscale copy of it"""
    px = image.load()
    newImage = Image.new("RGB", (image.width, image.height))
    newPx = newImage.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            pixel = px[x, y]
            # calculate graylevel
            graylevel = int(0.2125 * pixel[0] + 0.7152 * pixel[1] + 0.0722 * pixel[2])
            # set pixel to calculated gray
            newPx[x, y] = (graylevel, graylevel, graylevel)
    # return copy of grayscale image
    return newImage

def magnifyImage(image):
    """Takes the given image and returns a copy magnified by 2"""
    px = image.load()
    newImage = Image.new("RGB", (image.width * 2, image.height * 2))
    newPx = newImage.load()
    # iterate through every pixel
    for x in range(image.width):
        for y in range(image.height):
            pixel = px[x, y]
            # copy to new image
            newPx[x*2, y*2] = pixel         # top left
            newPx[x*2, y*2 + 1] = pixel     # bottom left
            newPx[x*2 + 1, y*2] = pixel     # top right
            newPx[x*2 + 1, y*2 + 1] = pixel # bottom right
    # return copy of magnified image
    return newImage

def main():
    """Allows user to use above functions on a given image"""
    print("**********Image Processing Toolkit*****************")
    # get image file for reading
    filename = input("Please enter path to image to process (Press enter to use default example): ")
    # use default boat example
    if len(filename) == 0:
        filename = "boat.jpg"
    # check that file is a jpg
    if not filename.endswith(".jpg"):
        print("ERROR: Must enter a jpg format image")
        quit()
    # open image and begin processing
    with Image.open(filename) as image:
        done = False
        newImage = None
        while not done:
            print("How should the image be processed?")
            print("1 - Create image negative")
            print("2 - Adjust brightness")
            print("3 - Flip vertically")
            print("4 - Flip horizontally")
            print("5 - Rotate to the left")
            print("6 - Find edges")
            print("7 - Create grayscale")
            print("8 - Magnify image by 4")
            print("9 - Display original image")
            print("10 - Display edited image")
            print("11 - Display this help")
            print("12 - Save and quit")
            print("13 - Save without quitting")
            print("14 - Quit without saving")
            # get user choice
            response = int(input("Enter your choice: "))
            # check that there is new image to save or open
            if (response == 10 or response == 12) and newImage is None:
                print("ERROR: Must edit image first")
            elif response == 1:
                newImage = createNegative(image)
            elif response == 2:
                amount = float(input("Adjustment between -1.0 and 1.0: "))
                newImage = adjustBrightness(image, amount)
            elif response == 3:
                newImage = flipVertically(image)
            elif response == 4:
                newImage = flipHorizontally(image)
            elif response == 5:
                newImage = rotateLeft(image)
            elif response == 6:
                threshold = int(input("Enter threshold(0 - 100): "))
                newImage = findEdges(image, threshold)
            elif response == 7:
                newImage = createGrayscale(image)
            elif response == 8:
                newImage = magnifyImage(image)
            elif response == 9:
                image.show()
            elif response == 10:
                newImage.show()
            elif response == 11:
                # do nothing
                done = False
            elif response == 12:
                newImage.save("output.jpg")
                done = True
            elif response == 13:
                newImage.save("output.jpg")
            elif response == 14:
                done = True
            else:
                print("ERROR: Invalid input, please try again")
            print() # new line for formatting
# call main function and start program
main()
