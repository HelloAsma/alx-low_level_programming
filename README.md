# Low_level_programming * C

![image](https://github.com/pixie-a/alx-low_level_programming/assets/101095081/7559d9fb-c13a-45b7-93ad-075665774537)

## Resources:

* [Everything you need to know to start with C](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2022/4/e0ccf91eec6b977a9e00ed384dc285df9c2772e3.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20231130%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20231130T225117Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=1d18c5bb6f4a976173f17bd6ec609e24fa56f568761ae785cc2bc959cffbdf54)

* [Explain to anyone](https://fs.blog/feynman-learning-technique/)

## Betty linter
To run the Betty linter just with command betty <filename>:

* Go to the Betty repository
* Clone the repo to your local machine
* cd into the Betty directory
* Install the linter with sudo ./install.sh
* emacs or vi a new file called betty, and copy the script below;
* Once saved, exit file and change permissions to apply to all users with chmod a+x betty
* Move the betty file into /bin/ directory or somewhere else in your $PATH with sudo mv betty /bin/

You can now type betty <filename> to run the Betty linter!

```
#!/bin/bash
# Simply a wrapper script to keep you from having to use betty-style
# and betty-doc separately on every item.
# Originally by Tim Britton (@wintermanc3r), multiargument added by
# Larry Madeo (@hillmonkey)

BIN_PATH="/usr/local/bin"
BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"

if [ "$#" = "0" ]; then
    echo "No arguments passed."
    exit 1
fi

for argument in "$@" ; do
    echo -e "\n========== $argument =========="
    ${BIN_PATH}/${BETTY_STYLE} "$argument"
    ${BIN_PATH}/${BETTY_DOC} "$argument"
done
