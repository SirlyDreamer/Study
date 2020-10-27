
import pandas as pd
import numpy as np




def load_data(filepath, index_col) :
    Data = pd.read_csv(filepath, sep=',', index_col=index_col)

    return Data
