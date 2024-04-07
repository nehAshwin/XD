# Create a file with a test input
echo "0123456789bcdef" > xd_input.txt


# Run your binary with the test input and redirect the output and errors to a separate file
./xd < xd_input.txt > test1.txt
xxd < xd_input.txt > normal_test.txt
my_returncode=$?

# Compare what was printed to stdout
diff test1.txt normal_test.txt
if [ $? -ne 0 ]; then
    echo "standard out doesn't match!"
    rm test1.txt
    rm normal_test.txt
    rm xd_input.txt
    exit 1
fi

# Compare the return codes.
if [ 0 -ne $my_returncode ] ; then
    echo "Return codes don't match!"
    rm test1.txt
    rm normal_test.txt
    rm xd_input.txt
    exit 1
fi

# Everything matches as expected!
echo "Working Correctly"
rm test1.txt
rm normal_test.txt
rm xd_input.txt
exit 0
