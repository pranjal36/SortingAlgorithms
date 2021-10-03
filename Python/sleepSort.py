# For each number in array we put timer according to the value and after that time is up value is printed/inserted into array.

from threading import Timer

def printVal(value):
    print(value)

def sleepSort(arr):
    for value in arr:
        # It will call "printVal" function after "value" seconds.
        t = Timer(value, printVal, args=[value])
        t.start()

          
def main():
    # Driver code to sleep sort algorithm
    arr = [5, 2, 7, 1, 4]    
    sleepSort(arr)


if __name__=="__main__":
    main()