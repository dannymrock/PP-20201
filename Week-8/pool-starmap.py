# start_map only python3
from multiprocessing import Pool, cpu_count

def power_n(x, n):
    return x ** n 
    
if __name__ == '__main__':

    result_seq = [power_n(x,2) for x in range(40)]
    print (result_seq)

    pool = Pool(processes=cpu_count())
    result_par = pool.starmap(power_n,[(x, 2) for x in range(40)])
    print (result_par)
