# start_map only python3
from multiprocessing import Pool, cpu_count

def power_n_list(x_list, n):
    return [x ** n for x in x_list]

def slice_data(data, nprocs):
    aver, res = divmod(len(data), nprocs)
    nums = []
    for proc in range(nprocs):
        if proc < res:
            nums.append(aver + 1)
        else:
            nums.append(aver)
    count = 0
    slices = []
    for proc in range(nprocs):
        slices.append(data[count: count+nums[proc]])
        count += nums[proc]
    return slices
    
if __name__ == '__main__':
    nprocs = cpu_count()
    pool = Pool(processes=nprocs)
    inp_lists = slice_data(range(40), nprocs)
    multi_result_par = [pool.apply_async(power_n_list, (inp, 2)) for inp in inp_lists]
    result = [x for p in multi_result_par for x in p.get()]
    print (result)
