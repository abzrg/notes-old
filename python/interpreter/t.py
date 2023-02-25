def f():
    # un-optimized
    #
    # thing = 'world'
    # print('hello hello ' + thing)

    # optimized
    print('hello hello ' + 'world')

if __name__ == "__main__":
    f()
