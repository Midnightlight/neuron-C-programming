# C Programming Neuron

Run the project:
```
chmod u+x run.sh
./run.sh
```

How is this project different from teacher's basic implementation:

- Support plug-and-play flexible different datasets (see [main.c](https://github.com/Midnightlight/neuron-C-programming/blob/master/main.c#L13), line 9 - 14).

- Changed the activation function from sigmoid function to linear function to make this a [regression model](https://machinelearningmastery.com/classification-versus-regression-in-machine-learning) (instead of a classification model in earlier).

- Add a learnable parameter for [bias](https://www.pico.net/kb/the-role-of-bias-in-neural-networks#:~:text=Bias%20allows%20you%20to%20shift,transposed%20by%20the%20constant%20value.). This effectively turns the model into [linear regression](https://machinelearningmastery.com/linear-regression-for-machine-learning/). 

- Add learning rate to prevent [divergence](https://machinelearningmastery.com/understand-the-dynamics-of-learning-rate-on-deep-learning-neural-networks/).

- Better result displays.