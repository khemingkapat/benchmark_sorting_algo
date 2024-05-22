for filename in ./tests/*.txt; do
    ./main "$filename" >> result.csv
done
