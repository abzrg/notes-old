# Jupyter alert when cell finishes work

```python
!pip install jupyternotify

# -----

%load_ext jupyternotify

# ----

%%notify          # <------
<your code here>  # when this cell finishes you'll be notified
```
