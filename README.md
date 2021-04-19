Run the project:
```
chmod u+x run.sh
./run.sh
```

What is new:
- Support Plug-and-play flexible datasets (see main.c).
- Changed activation function from sigmoid function to linear function to make this a regression model.
- Add a learnable parameter for [bias](https://www.pico.net/kb/the-role-of-bias-in-neural-networks#:~:text=Bias%20allows%20you%20to%20shift,transposed%20by%20the%20constant%20value.).
- Better display.
- Add learning rate to prevent learning divergence.