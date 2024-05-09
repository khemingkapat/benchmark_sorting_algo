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
    def __init__(self):
        pass

    def get_output(self) -> Tuple:
        n = np.random.randint(0,1_000_000)
        mean = np.random.rand()*100
        sd = abs(np.random.rand())*5

        arr = np.random.normal(mean,sd,n)

        return ([n,mean,sd],arr)

normal = Normal()
normal.generate_test(5)
