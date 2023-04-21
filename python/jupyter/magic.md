# Jupyter magic commands


- use `%lsmagic` command to get a list of all magic commands.
- these commands are grouped into line (`%`) and cell (`%%`) commands

- The exclamation mark, `!,` is used for executing commands from the underlying
  operating system; here is an example using Windows' `dir`:

  ```
  !dir
  # Result:
  Volume in drive C has no label.
   Volume Serial Number is 52EA-B90C

   Directory of C:\Users\Root

  27/11/2018  13:08    <DIR>          .
  27/11/2018  13:08    <DIR>          ..
  23/08/2016  11:00             2,258 .adalcache
  12/09/2016  18:06    <DIR>          .anaconda
  [...]
  ```

- The question `?` mark is used to provide in-notebook help:

  ```python
  import pandas as pd
  import numpy as np

  df = pd.DataFrame([[np.nan, 2, np.nan, 0],
                     [3, 4, np.nan, 1],
                     [np.nan, np.nan, np.nan, 5],
                     [np.nan, 3, np.nan, 4]],
                     columns=list('ABCD'))

  df.fillna?
  ```

  result:

  ```
  Signature: df.fillna(value=None, method=None, axis=None, inplace=False, limit=None, downcast=None, **kwargs)
  Docstring:
  Fill NA/NaN values using the specified method

  Parameters
  ----------
  value : scalar, dict, Series, or DataFrame
      Value to use to fill holes (e.g. 0), alternately a
      dict/Series/DataFrame of values specifying which value to use for
      each index (for a Series) or column (for a DataFrame). (values not
      in the dict/Series/DataFrame will not be filled). This value cannot
      be a list.
  method : {'backfill', 'bfill', 'pad', 'ffill', None}, default None
      Method to use for filling holes in reindexed Series
      pad / ffill: propagate last valid observation forward to next valid
      backfill / bfill: use NEXT valid observation to fill gap
  axis : {0, 1, 'index', 'columns'}
  inplace : boolean, default False
      If True, fill in place. Note: this will modify any
      other views on this object, (e.g. a no-copy slice for a column in a
      DataFrame).
  limit : int, default None
      If method is specified, this is the maximum number of consecutive
      NaN values to forward/backward fill. In other words, if there is
      a gap with more than this number of consecutive NaNs, it will only
      be partially filled. If method is not specified, this is the
      maximum number of entries along the entire axis where NaNs will be
      filled.
  downcast : dict, default is None
      a dict of item->dtype of what to downcast if possible,
      or the string 'infer' which will try to downcast to an appropriate
      equal type (e.g. float64 to int64 if possible)

  See Also
  --------
  reindex, asfreq

  Returns
  -------
  filled : DataFrame
  File:      c:\users\root\anaconda3\lib\site-packages\pandas\core\frame.py
  Type:      method
  ```


## References

- [magics -- jupyter docs](https://ipython.readthedocs.io/en/stable/interactive/magics.html)
- [stackoverflow post](https://stackoverflow.com/a/53498455/13041067)
