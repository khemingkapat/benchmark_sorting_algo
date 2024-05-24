import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os


df = pd.read_csv("./result.csv")
df.sort_values(["Algo","FileName"],inplace=True)
df[["n","min","max","arg"]] = np.nan


f = open("./tests/normal1.txt","r")

directory =  os.fsencode("./tests/")
tests_args = dict()

for file in os.listdir(directory):
    filename = os.fsencode(file)
    full_filename = str(os.path.join(directory,filename),"utf-8")
    args = list(map(lambda s : s.strip(),open(full_filename,"r").readlines()))
    args = args[:args.index("START")]
    args = list(map(int,args))
    # print(full_filename)
    tests_args[full_filename] = args


for idx,row in df.iterrows():
    # print(row["FileName"])
    if len(tests_args[row["FileName"]]) == 3:
        df.at[idx,"n"] = tests_args[row["FileName"]][0]
        df.at[idx,"min"] = tests_args[row["FileName"]][1]
        df.at[idx,"max"] = tests_args[row["FileName"]][2]
    else:
        df.at[idx,"n"] = tests_args[row["FileName"]][0]
        df.at[idx,"min"] = tests_args[row["FileName"]][1]
        df.at[idx,"max"] = tests_args[row["FileName"]][2]
        df.at[idx,"arg"] = tests_args[row["FileName"]][3]

def extract_test(string):
    string = string.split("/")[-1]
    string = string.split(".")[0]
    string = "".join([i for i in string if not i.isdigit()])
    return string


df["FileName"] = df["FileName"].apply(extract_test)
df = df.rename(columns={"FileName":"Test"})

df.to_csv("result2.csv",index=False)
