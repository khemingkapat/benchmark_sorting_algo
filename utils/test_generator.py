from abc import ABC, abstractmethod
from typing import Tuple
import numpy as np


class Writer(ABC):

    @abstractmethod
    def get_output(self) -> Tuple:
        pass

    def write_output(self, filename, arr,args):
        file = open(filename,"w+")

        list_str = lambda x: "\n".join(list(map(str, x)))

        arg = list_str(args)
        lines = list_str(arr)

        file.writelines(arg)
        file.writelines("\n")
        file.writelines("START\n")
        file.writelines(lines)

        file.close()

    def generate_test(self, n_times):
        for i in range(1, n_times + 1):
                args, arr = self.get_output()
                self.write_output(f"tests/{self.__class__.__name__.lower()}{i}.txt",arr,args)
            

class Normal(Writer):
    def get_output(self) -> Tuple:
        n = np.random.randint(0,50_000)
        maximum = np.random.randint(0,101)
        minimum = np.random.randint(-100,0)

        arr = np.random.randint(minimum,maximum,n)

        return ([n,minimum,maximum],arr)

class Descend(Writer):
    def get_output(self)->Tuple:
        n = np.random.randint(0,50_000)
        maximum = np.random.randint(0,101)
        minimum = np.random.randint(-100,0)

        arr = -np.sort(-np.random.randint(minimum,maximum,n))

        return ([n,minimum,maximum],arr)

class Partial(Writer):
    def get_output(self)->Tuple:
        n = np.random.randint(0,50_000)
        maximum = np.random.randint(0,101)
        minimum = np.random.randint(-100,0)

        arr = np.sort(np.random.randint(minimum,maximum,n))

        list_idx = list(range(n))
        np.random.shuffle(list_idx)

        shuffle_precent = np.random.randint(20,80)

        for _ in range(int(n*shuffle_precent/100)//2):
            arr[list_idx[0]],arr[list_idx[1]] = arr[list_idx[1]],arr[list_idx[0]]
            
            list_idx.pop(0)
            list_idx.pop(0)

            
        return ([n,minimum,maximum,shuffle_precent],arr)

class Sorted(Writer):
    def get_output(self)->Tuple:
        n = np.random.randint(0,50_000)
        maximum = np.random.randint(0,101)
        minimum = np.random.randint(-100,0)

        arr = np.sort(np.random.randint(minimum,maximum,n))

        return ([n,minimum,maximum],arr)

Sorted().generate_test(100)
# Normal().generate_test(100)
# Descend().generate_test(100)
# Partial().generate_test(100)



