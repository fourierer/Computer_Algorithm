import torch


def RoPE(q):
    # 以长度为4，dim维度为6的q展示llama是如何实现RoPE的
    seq_len, dim = q.shape # [4, 6]

    # 将q在其embedding 