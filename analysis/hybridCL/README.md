
--------------------------------------------------------
# Running the Hybrid-New CLs in Combine
-------------------------------------------------------- 

## Step 1) Run toys
This is a time consuming step, need to run as jobs. 

Test locally with one job: 
- `combine datacardM800.txt -m 800 -M HybridNew --freq -s 123 --saveToys --saveHybridResult`

To run on the batch queue calls combine.py in the datacard directory:
Can see example of how to submit in `submitcombine.sh`.


## Step 2) Get the quantiles

Test locally with one job:
- `combine datacardM800.txt -m 800 -M HybridNew --freq --grid=higgsCombineTest.HybridNew.mH800.123.root --expectedFromGrid=0.5`




