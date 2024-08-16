import random
import time
import matplotlib.pyplot as plt

def generate_matrix(N):
    return [[random.random() for _ in range(N)] for _ in range(N)]

def multiply_matrices(a, b):
    N = len(a)
    result = [[0.0] * N for _ in range(N)]
    
    start=time.time()
    for i in range(N):
        for j in range(N):
            result[i][j] = sum(a[i][k] * b[k][j] for k in range(N))
    end=time.time()
    return end-start

def main():
    start=time.time()
    sizes = [64, 128, 256, 512, 1024]
    times=[]
    mult_times=[]
    for N in sizes:
        start_time = time.time()

        a= generate_matrix(N)
        b=generate_matrix(N)

        mult_times.append(multiply_matrices(a, b))
        
        end_time = time.time()
        
        times.append(end_time - start_time)

    end=time.time()
    print(f"Total time: {(end-start):.6f} seconds")
    print("Matrix size","Time for iteration","Time for multiplication")
    for i in range(5):
        print(sizes[i],times[i],mult_times[i])

    plt.plot(sizes,times, marker='o', linestyle='-', color='b')
    plt.xlabel("Size of matrix")
    plt.ylabel("Execution time( in s)")
    plt.title("Comparison using double in python")
    plt.savefig("2b.png")

    

if __name__ == "__main__":
    main()
