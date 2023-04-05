```sh
# first check packages
twine check dist/*

# first upload to test pypi
# r: repository
twine upload -r testpypi dist/*

# upload to pypi.org
twine upload dist/*
```
