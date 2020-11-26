from multiprocessing import Pool, cpu_count

def square(x):
    return x*x 
    
if __name__ == '__main__':

    result_seq = [square(x) for x in range(4000)]
    print result_seq

    pool = Pool(processes=cpu_count())
    result_par = pool.map(square, range(4000))
    print result_par
