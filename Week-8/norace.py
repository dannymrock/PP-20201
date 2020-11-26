from multiprocessing import Process, Value

def f(num):
    for i in range(100000):
        with num.get_lock():
            num.value +=1

if __name__ == '__main__':
    num = Value('i', 0)
    
    p = Process(target=f, args=(num, ))
    p.start()
    for i in range(100000):
        with num.get_lock():
            num.value +=1
    p.join() 

    print(num.value)

