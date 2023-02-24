# Github Actions

## Exmple situation

imagine that every time you push a new code, you’d like to execute a series of unit tests on it on an Ubuntu machine that has a specific configuration.

The long answer 👉 : you push your code to Github, connect to a server you’ve already created, pull the new version of the code, run the tests, and wait for the final output. Needless to say that it’s a tedious and lengthy process.
Believe me, I did that, a lot, in the past and it’s not fun.

The short answer 👉: you create a workflow that gets executed at every push and does the same series of actions: spinning up a machine, pulling the code, running the series of tests, and showing the results in a console.


## Terminology

- automates the build, test, and deployment of software
- it allows you also to run any arbitrary code on your repository when a specific event happens.

- __Event__: Anything that can happen in a Github repository:
  - push
  - pull request
  - commenting on an issue
  - [...](https://docs.github.com/en/actions/learn-github-actions/events-that-trigger-workflows#webhook-events)

- __Workflows__: A workflow is an automated process composed of a series of jobs that gets executed when it's triggered by an _event_
  - a workflow is defined in a YML file (`.github/workflows` at the root of the project).
  - a repository can have multiple workflows.
    - each workflow is defined in a YML file insdie the `.workflows` folders.

- __Jobs__: A job is a series of tasks that gets executed in a _workflow_.
  - each step is either a script or a Github action.
  - a workflow can have multiple tasks jobs that run in parallel.

- __Runners__: Runners are _processes_ on a server that run the workflow.
  - each runner is responsible for executing a given _job_.
  - Runners are hosted in the cloud but they can also be self-hosted in custom cloud environment.


```
               +--------------------------------------------+
  +-------+    |  +----------------+    +----------------+  |
  | Event |-------|    Runner 1    |----|    Runner 2    |  |
  +-------+    |  +----------------+    +----------------+  |
               |                                            |
 (the trigger) |  +----------------+    +----------------+  |
               |  | +------------+ |    | +------------+ |  |
               |  | |   Step 1:  | |    | |   Step 1:  | |  |
               |  | | run script | |    | | run script | |  |
               |  | +------------+ |    | +------------+ |  |
               |  |                |    |                |  |
               |  | +------------+ |    | +------------+ |  |
               |  | |   Step 2:  | |    | |   Step 2:  | |  |
               |  | | run action | |    | | run script | |  |
               |  | +------------+ |    | +------------+ |  |
               |  |                |    |                |  |
               |  |                |    |                |  |
               |  |                |    |                |  |
               |  +----------------+    +----------------+  |
               +--------------------------------------------+
                               Git workflow
```


- __Actions__: are individual tasks
  - are called inside a _job_
  - are used to perform complex tasks that you may call multiple times and
    import into your workflows
    - publishing a Python package to PyPi
    - sending a notification email
    - setting Python to a specific version before running a script
    - ...
  - You can build your own action or you can
    [reuse](https://github.com/marketplace?type=actions) some open source
    actions


## Example

```yml
on:
  push:
    branches:
      - master
jobs:
  print_hello:
    runs-on: ubuntu-latest
    steps:
      - run: echo "Hello World!"
  list_root:
    runs-on: ubuntu-latest
    steps:
      - run: ls /
```


- `on`: the event that triggers the workflow
- `runs-on`: the machine each job should run (e.g. ubuntu-latest)
- `jobs`: the list of jobs that make the workflow
- `steps`: the series of tasks that run inside each job
- `run`: the command that gets executed


## References:

Notes exactly taken from the following:
- [Github Actions— Everything You Need to Know to Get Started](https://towardsdatascience.com/github-actions-everything-you-need-to-know-to-get-started-537f1dffa0ed)

- [Github's own example](https://docs.github.com/en/actions/guides)
