# build2 Package for pmp-library

This project is a [build2](https://build2.org) package repository that provides access to [`pmp-library`](https://github.com/pmp-library/pmp-library), a modern C++ open-source library for processing and visualizing polygon surface meshes.

[![Official](https://img.shields.io/website/https/github.com/pmp-library/pmp-library.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/pmp-library/pmp-library)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/pmp-library.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/pmp-library)
[![cppget.org](https://img.shields.io/website/https/cppget.org/pmp-library.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/pmp-library)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/pmp-library.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/pmp-library)

## Usage
Make sure to add the stable section of the [`cppget.org`](https://cppget.org/?about) repository to your project's `repositories.manifest` to be able to fetch this package.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/pmp-library.git

Add the respective dependency in your project's `manifest` file to make the required packages available for import.
The `libpmp-vis` package requires `libpmp` package as its core module and adds the visualization features to the standard mesh processing facilities.

    depends: libpmp ^3.0.0
    depends: libpmp-vis ^3.0.0

To import the respective library targets include one of the following declarations in a `buildfile`.

    import pmp = libpmp%lib{pmp}
    import pmp_vis = libpmp-vis%lib{pmp-vis}

## Configuration
There are no configuration options available.

## Issues and Notes
- Naming Scheme:
    + Repository Name: Same as the upstream repository: `pmp-library`
    + Project Name: Same as the upstream repository and the project name given in the upstream CMake file: `pmp-library`
    + Library Name: To be consistent with programming practices, we wanted the library name to be the name of the upstream include folder: `lib{pmp}`
    + Package Name: According to the recommended build2 practices, the respective library package gets the prefix `lib` and its name becomes `libpmp`.
    + Similar for `lib{pmp-vis}` in package `libpmp-vis`

## Contributing
Thanks in advance for your help and contribution to keep this package up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/pmp-library/issues) for everything that is not described below.

### Recommend Updating Version
Please, file an issue on [GitHub](https://github.com/build2-packaging/pmp-library/issues) with the new recommended version.

### Update Version by Pull Request
1. Fork the repository on [GitHub](https://github.com/build2-packaging/pmp-library) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
6. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
7. Run `bdep ci` and test for errors.
8. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
9. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions
1. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
4. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
5. Run `bdep ci` and test for errors and warnings.
6. When successful, run `bdep release --tag --push` to push new tag version to repository.
7. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
