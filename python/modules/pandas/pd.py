import pandas as pd

# ------------------
# Series
#
# Creating a 'Series' which is basically a column in a spreadsheet
# It contains:
# 1. list of indices
# 2. the list of data

transport_means: list[str] = ["Boat", "Car", "Bike", "Truck"]
tm_series: pd.Series = pd.Series(
    transport_means, name="means"
)  # dtype: object (strings)

numbers: list[int] = [1, 55, 99, 43]
num_series: pd.Series = pd.Series(numbers, name="numbers")  # dtype: int64


# ------------------
# DataFrame
#
# It's like the whole spread sheet that contains:
# 1. list of indices
# 2. one or more series

some_data: list[tuple[str, int]] = list(zip(transport_means, numbers))
some_data_frame: pd.DataFrame = pd.DataFrame(some_data, columns=["means", "numbers"])

# - To access a series
some_data_frame['means']

# - Get dtypes of all series
some_data_frame.dtypes


# ------------------
# Load the csv files
df = pd.read_csv("./us_scatter.csv")


# ------------------
# Inspect
df.head()
df.tail()
df.dtypes
df.describe()  # Some statistics stuff. Only works with numeric dtypes
df.columns  # list of column names
df.shape  # size of the spreadsheet


# ------------------
# columns and rows
df['title'] # all the rows associated with 'title' column (series)
df.loc[4]  # all the columns associated with the 4th row


# ------------------
# To change the index (maybe the dataset has a column associate with unique IDs)
# really usefull for time series data. with this you can jump to certain timestamp
df = df.set_index('index')
df.loc[1]


# ------------------
# Subsetting data

# subsetting columns
df = df[['title', 'views', 'likes', 'dislikes']]

# subsetting rows (using loc)
df_loc = df.loc[df['views'] > 1_000_000]  # views with more than one million


# subsetting using DataFrame.query()
df_query = df.query('views > 1000000')

# subseting using ~ and isnan()
df_nan = df.loc[~df['views'].isna()]


# --------------------------
# casting dtypes

df['views'] = df['views'].astype('str')
df['likes'] = df['likes'].astype('int')
# df['publishTime'] = pd.to_datetime(df['publishTime'])  # Convert to datetime type
df['dislikes'] = pd.to_numeric(df['dislikes'].astype('str'))



# ----------------------------
# Creating new columns

df['likes_to_dislike_ratio'] = df['likes'] / df['dislikes']  # rhs is a data series


# ----------------------------
# Creating a new row (append to the end)

df_to_append = df.tail(1)
df_concat = pd.concat([df, df_to_append])


# ---------------------------------
# plot

from matplotlib import pylab as plt
plt.style.use('ggplot')


df['views'].plot(kind='hist')
