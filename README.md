# console-cpp-simple

# Recipe

FROM [codenvy/cpp_gcc](https://hub.docker.com/r/codenvy/cpp_gcc/)

# Commands

| #       | Description           | Command  |
| :------------- |:-------------| :-----|
| 1      | Build | `cd ${current.project.path} && make` |
| 2      | Run      |   `${current.project.path}/a.out` |

# Output

The app will print Hello World to the console

