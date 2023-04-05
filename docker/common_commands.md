
## List Stuff

List not just running but exited and removed containers too.

```
docker ps -a/--all
```

List all the images

```
docker images
```


## Run a container

Burn after reading!

```sh
docker run -it -rm <image-name-or-id>
```

Don't burn it! Later attach to it.

```sh
docker run -it -rm <image-name-or-id>

docker start -a/--attach -i/--interactive <container ID>  # start the exited container
docker attach <container ID> # attach to your container
```


## Rename tag

```sh
docker image tag <image>:<oldtag> <image>:<newtag>
```


## Inspect an Image


```sh
docker image inspect
```
