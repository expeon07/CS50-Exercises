# get height function
def get_int():
    height = -1
    while type(height).__name__ != 'int' or height < 1 or height > 8:
        height = input("Height: ")
        try:
            height = int(height)
        except ValueError:
            continue
    return int(height)

# execute get_int() function
wall = get_int()

# make the wall
for row in range(wall + 1):
    if row > 0:
        for space in range((wall - row)):
            print(" ", end='')
    
        for block in range(row):
            print("#", end='')
        
        print('')
