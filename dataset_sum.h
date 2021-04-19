/*
    This dataset is hand-crafted.
    The input is 3 numbers; the output is their sum. 
*/

#ifndef _DATASET_H_
#define _DATASET_H_

const int INPUT_SIZE = 3;

// Train dataset
const int TRAIN_COUNT = 6;
double input_train[TRAIN_COUNT][INPUT_SIZE] = {
    {1, 1, 1},
    {-1, 2, 1},
    {2, 1, 0},
    {3, -1, -1},
    {4, -3, 0},
    {4, 1, 3}};

double output_train[TRAIN_COUNT] = {
    3,
    2,
    3,
    1,
    1,
    8};

// Test dataset
const int TEST_COUNT = 6;
double input_test[TEST_COUNT][INPUT_SIZE] = {
    {1, -1, -1},
    {-1, 2, 3},
    {2, -1, -3},
    {3, -1, -1},
    {-4, -3, 0},
    {-4, 1, 3}};
double output_test[TEST_COUNT] = {
    -1,
    4,
    -2,
    1,
    -7,
    0};

#endif /* _DATASET_H_ */
