import time
from multiprocessing import Pool, cpu_count

def func(n):
    sum=0
    for x in range(10000):
        sum += x*x
        return sum

if __name__ == "__main__":
    t1 = time.time()
    # Sequential
    result = []
    for x in range(2000000):
        result.append(func(x))
        
    print("Serial time: ", time.time()-t1)

    #Parallel v1
    t2 = time.time()
    pool = Pool(processes=cpu_count())
    result = pool.map(func, range(2000000))
    print("Parallel time (map): ", time.time()-t2)

    #Parallel v2
    t3 = time.time()
    result = pool.map_async(func, range(2000000))
    #result.get()
    print("Parallel time (map): ", time.time()-t3)

    
    
    
