# Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

# Implement the MovingAverage class:

# MovingAverage(int size) Initializes the object with the size of the window size.
# double next(int val) Returns the moving average of the last size values of the stream.

class MovingAverage:

    def __init__(self, size: int):
        self.size = size
        self.window = []
        self.sum = 0

    def next(self, val: int) -> float:
        # Add new value to window and update sum
        self.window.append(val)
        self.sum += val

        # If window exceeds size, remove oldest value
        if len(self.window) > self.size:
            self.sum -= self.window.pop(0)
        
        # Calculate and return average
        return self.sum / len(self.window)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)

def main():
    movingAverage = MovingAverage(3)
    print("the moving average is: ", movingAverage.next(1)) # 1
    print("the moving average is: ", movingAverage.next(10)) # 5.5
    print("the moving average is: ", movingAverage.next(3)) # 4.66667
    print("the moving average is: ", movingAverage.next(5)) # 6

if __name__ == "__main__":
    main()
