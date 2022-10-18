# 数组
## I 声明数组
```
type arrayName[ arraySize ];
# type : 任意有效的 C 数据类型
# arrarName : 声明的数组名称
# arraySize : 包含type元素个数
（arraySize可以理解成开区间，不包含）
```
#### 举例：
声明一个类型为 double 的包含 10 个元素的数组 balance
```C
double balance[10];
```
## II 初始化数组
### i 规定数组大小
```C
type arrayName[ arraySize ] = { item1,  item2, item3, item4, item(arraySize) };
```
数组中元素数目 x 满足：0 < x < arraySize
如果赋值元素数目 x 小于 arraySize，则剩余元素补 0
#### 举例:
```C
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```
### ii 不规定数组大小
```C
type arrayName[] = { item1,  item2, item3, item4, itemn };
```
数组大小未规定，则自动匹配元素数目 n
#### 举例：
```C
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```
## III 访问数组元素
### i 对元素写入
```C
arrayName[index] = val;
```
#### 举例：
```C
balance[0] = 1000.0;
```
### ii 对元素读取
```C
arrayName[index];
```
#### 举例：
```C
int number[3] = {1,2,3};
printf("输出值为：%d",number[0]);
# 输出值为： 1
```
# 结构体struct

# 共用体union

# 枚举类型enum

# 空类型void