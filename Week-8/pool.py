from multiprocessing import Pool

def func(x):
    return [[len(z),z] for z in x]

if __name__ == '__main__':
    pool = Pool(processes=8)
    f = open('file1.txt','r')
    l = f.readlines()
    f.close()

    d = [ w.strip() for w in l ]
    print d
    result = pool.apply_async(func, [d])

    print result.get()
