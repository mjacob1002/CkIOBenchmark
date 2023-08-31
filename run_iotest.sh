for i in 0 1 2
do
    python3 /scratch/mzu/yanniz3/CkIOBenchmark/TEST_FILES/create_test_files.py /scratch/mzu/yanniz3/CkIOBenchmark/TEST_FILES/file16gb 16
    sleep 30
    sbatch $1
    sleep 120
    rm /scratch/mzu/yanniz3/CkIOBenchmark/TEST_FILES/file16gb
    sleep 30
done
