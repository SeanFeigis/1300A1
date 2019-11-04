echo "Testing daysCalculatorA..."
echo "./daysCalculatorA : answer should be an error or usage message"
./daysCalculatorA 
echo "------"
echo "./daysCalculatorA 30 2 2018 12 12 2018 : answer should be an error message"
./daysCalculatorA 30 2 2018 12 12 2018
echo "------"
echo "./daysCalculatorA 9 14 2019 9 22 2019 : answer should be an error message"
./daysCalculatorA 9 14 2019 9 22 2019 
echo "------"
echo "./daysCalculatorA 14 9 2019 9 12 2019 : answer should be 86"
./daysCalculatorA 14 9 2019 9 12 2019 
echo "------"
echo "./daysCalculatorA 27 8 2016 1 12 2016 : answer should be 96"
./daysCalculatorA 27 8 2016 1 12 2016
echo "------"
echo "./daysCalculatorA 1 1 2018 31 12 2018 : answer should be 364"
./daysCalculatorA 1 1 2018 31 12 2018
echo "------"

echo "Testing daysCalculatorB..."
echo "./daysCalculatorB : answer should be an error or usage message"
./daysCalculatorB 
echo "------"
echo "./daysCalculatorB 30 2 2018 12 12 2018 include : answer should be an error message"
./daysCalculatorB 30 2 2018 12 12 2018 include
echo "------"
echo "./daysCalculatorB 9 14 2019 9 22 2019 includes : answer should be an error message"
./daysCalculatorB 9 14 2019 9 22 2019 includes
echo "------"
echo "./daysCalculatorB 14 9 2019 9 12 2019 include : answer should be 87"
./daysCalculatorB 14 9 2019 9 12 2019 include
echo "------"
echo "./daysCalculatorB 27 8 2016 1 12 2016 include  : answer should be 97"
./daysCalculatorB 27 8 2016 1 12 2016 include
echo "------"
echo "./daysCalculatorB 1 1 2018 31 12 2018 include : answer should be 365"
./daysCalculatorB 1 1 2018 31 12 2018 include
echo "------"

echo "Testing daysCalculatorC..."
echo "./daysCalculatorC : answer should be an error or usage message"
./daysCalculatorC
echo "------"
echo "./daysCalculatorC 30-02-2018 12-12-2018 include : answer should be an error message"
./daysCalculatorC 30-02-2018 12-12-2018 include
echo "------"
echo "./daysCalculatorC 14-09-2019 09-22-2019 includes : answer should be an error message"
./daysCalculatorC 14-09-2019 22-09-2019 includes
echo "------"
echo "./daysCalculatorC 14-09-2019 09-12-2019 include : answer should be 87"
./daysCalculatorC 14-09-2019 09-12-2019 include
echo "------"
echo "./daysCalculatorC 27-08-2016 01-12-2016 include  : answer should be 97"
./daysCalculatorC 27-08-2016 01-12-2016 include
echo "------"
echo "./daysCalculatorC 01-01-2018 31-12-2018 include : answer should be 365"
./daysCalculatorC 01-01-2018 31-12-2018 include
echo "------"

echo "Testing daysCalculatorE..."
echo "./daysCalculatorE 30-02-2018 12-12-2019 include : answer should be an error message"
./daysCalculatorE 30-02-2018 12-12-2019 include
echo "------"
echo "./daysCalculatorE 14-09-2019 22-09-2020 include : answer should be 375"
./daysCalculatorE 14-09-2019 22-09-2020 include
echo "------"
echo "./daysCalculatorE 14-09-2016 09-12-2018 : answer should be 816"
./daysCalculatorE 14-09-2016 09-12-2018 
echo "------"
echo "./daysCalculatorE 27-08-2016 01-12-2018 include  : answer should be 827"
./daysCalculatorE 27-08-2016 01-12-2018 include
echo "------"
echo "./daysCalculatorE 01-01-2016 01-12-2020 : answer should be 1796"
./daysCalculatorE 01-01-2016 01-12-2020
echo "------"

