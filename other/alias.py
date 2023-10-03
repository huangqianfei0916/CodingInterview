'''
Author: huangqianfei
Date: 2022-10-19 19:02:41
Description: Alias实现不等概率事件下O(1)时间复杂度的抽
图嵌入中计算每个节点的accept_prob和alias_index存储起来，在游走时候O(1)alias_sample
'''

import numpy as np

# accept_prob:大于1的位置是调整后的值，小于1的位置值不变（或者可以理解为属于本位置的概率）[这里针对prob * len]
# alias_index:填充的下标，当随机数字大于accept_prob对应位置的prob时，返回这个数组的index
def create_alias_table(prob):
    """
    :param Prob_val: 归一化概率
    :return: accept_prob，alias_index
    """
    length = len(prob)
    # 初始化两个数组
    accept_prob = np.zeros(length)
    alias_index = np.zeros(length, dtype=np.int)

    # 分别存储大于小于1的节点下标
    small_list = []
    large_list = []

    for index, prob in enumerate(prob):
        accept_prob[index] = length * prob

        if accept_prob[index] < 1.0:
            small_list.append(index)
        else:
            large_list.append(index)

    while small_list and large_list:
        small_index = small_list.pop()
        large_index = large_list.pop()

        # 记录接受了谁的补助
        alias_index[small_index] = large_index
        # 补充的原则是：大的概率要把小的概率补满
        accept_prob[large_index] = accept_prob[large_index] + accept_prob[small_index] - 1.0
        # 判断剩下的值
        if accept_prob[large_index] < 1.0:
            small_list.append(large_index)
        elif accept_prob[large_index] == 1.0:
            pass
        else:
            large_list.append(large_index)

    return accept_prob, alias_index


def alias_sample(accept_prob, alias_index):
    N = len(accept_prob)

    # 随机选择一列
    random_num1 = int(np.floor(np.random.rand()*N))
    # 在某一列中判断选择哪一个
    random_num2 = np.random.rand()

    if random_num2 < accept_prob[random_num1]:
        return random_num1
    else:
        return alias_index[random_num1]

if __name__ == "__main__":
    prob = [0.3, 0.1, 0.1, 0.5]
    accept_prob, alias_index = create_alias_table(prob)
    print(accept_prob)
    print(alias_index)