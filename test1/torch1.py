import torch
import numpy as np

a = torch.tensor(
    [
        [
            [1.0,2.0,3.0],
            [4.0,5.0,9.0]
        ],
        [
            [1.0,2.0,3.0],
            [4.0,5.0,6.0]
        ]
    ]
)

print(a.shape)
# m = 4
# v = 2.581

d1 = np.sqrt(np.var([1, 2, 3, 4, 5, 9]) + 1e-05)
print(d1)
print("---")


ln = torch.nn.LayerNorm([2, 3], elementwise_affine = False)
ln_out = ln(a)
ln.state_dict()
print(ln_out)
print(ln.state_dict())