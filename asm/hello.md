# X86 NASM Assembly

I just did it, on a mac!

## Docker part

Install an x86 linux container image

```sh
docker pull --platform linux/amd64 ubuntu:latest
```

Then run it

```sh
# Optional (I have multiple ubuntu images to remember the which one is which):
docker image tag ubuntu:latest ubuntu:amd64

# Run the container
docker run -it ubuntu:latest


# - for later attchment

docker ps -a  # enquery list of previously run containers

docker attach <container-name>
# or
docker start -ai <container-name>
```


## Prerequisits


```sh
# I essentially want to use this as a second machine, so I don't let it be minimized
unminize # then enter y<cr>

apt update
apt install vim git build-essential man-db nasm
```


## Hello World


```asm
section .data

section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, text
	mov rdx, 14
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
```

Assemble, link and run

```
# ASSEMBLE (create an object file in elf64 format)
$ nasm -f elf64 hello.asm # you could pass '-o hello.o', but it's done automatically

# LINK (link and create an executable)
$ ld hello.o -o hello

# Run it
$ ./hello
```
