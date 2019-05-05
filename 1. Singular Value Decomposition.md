## 1. Singular Value Decomposition 

 : 특정 조건에서만 사용가능했던  $$A = PDP^{-1}$$를  $$m \times n $$ 행렬인 $$A$$에서 사용할 수 있도록 확장한 형태이다.


$$
A = U\Sigma V^T
$$
여기서  $$U$$는 크기가 $$m \times m$$,  $$ V$$ 는크기가 $n \times n$ 인 직교행렬이고, $\Sigma$는 주대각 성분이 $A$의 특이값이고 나머지 성분은 0인 $m \times n$ 행렬이다. 

1. $V = \begin{bmatrix} \mathbf{v}_1 & \mathbf{v}_2  & \cdots & \mathbf{v}_n \end{bmatrix}$ 은 $A^TA$ 를 직각대각화한다고 놓는다.

2. $\lambda_1, \lambda_2,..., \lambda_k$가 $V$의 열벡터에 대응하는 $A^TA$ 의 0이 아닌 고유값일 때 $\Sigma$ 의 영이 아닌 대각성분은  $\sigma_1 =\sqrt{\lambda_1}, \ \ \sigma_2 =\sqrt{\lambda_2}, \ \ ... \ \ ,  \ \sigma_k =\sqrt{\lambda_k}$  이다.
   $$
   AA^T = U \Sigma V^T(U \Sigma V^T)^T\\
   =U \Sigma V^TV\Sigma^TU^T\\
   =U\Sigma \Sigma^T U^T\\ \ \ \  
   위의 \ 형태를  \  P \ D \ P^{-1}와 \ 비교하면,
   \\ \Sigma \Sigma^T = D \ 이다. \ D의 \ 원소는 \ \lambda_i \ 이다. \\
   \therefore \Sigma의 \ 원소 \ \sqrt{\lambda_i} \ 이다.
   $$

3. $V$의 열벡터는 $\sigma_1 \ge \sigma_2 \ge \cdots\ge \sigma_k \ge 0 $ 를 만족시키도록 배열시킨다.

4. $\mathbf{u}_i = \frac{A \mathbf{v}_i} {\begin{Vmatrix} A\mathbf{v}_i \end{Vmatrix}} = \frac{1}{\sigma_i}A\mathbf{v}_i \ \ \ \   (i = 1, 2, ..., k)$ 
   $$
   \because \ A = U\Sigma V^T\\
   AV = U\Sigma V^T V \ (\therefore V^TV = I) \\
   \frac{1}{\Sigma} AV = U
   \\ \to  \frac{1}{\sigma_i}A\mathbf{v}_i = \mathbf{u}_i
   $$

5. $\begin{Bmatrix} \mathbf{u}_1 , \mathbf{u}_2 , \cdots , \mathbf{u}_k \end{Bmatrix}$는 col($A$)의 정규직교기저이다.



## 2. Principal Component Analysis

> 역할

주대각 성분을 기준으로 삼고 내적을 이용하여 좌표를 기준의 좌표로 변환함으로써 높은 차원의 데이터를 낮은 차원의 데이터로 압축 할 수 있다.  (주대각 성분을 벗어난 데이터들은 노이즈인 경우가 많으므로 무시할 수 있다.)
$$
A를 \ 3\times n이고 \ 열벡터로 \ 이루어진 \ 행렬이라 \ 하자 \\  
A = \begin{bmatrix} \mathbf{x_1} & \mathbf{x_2} & \cdots & \mathbf{x_n}\end{bmatrix}\\
\bar{\mathbf{x}}를 \ 열벡터의 \ 평균이라 \ 놓는다. \\
B = \sum_{i=1}^n (\mathbf{x_i} - \bar{\mathbf{x}})(\mathbf{x_i} - \bar{\mathbf{x}})^T \ \ \  ( \bar{\mathbf{x}} \ 평균값을 기준으로 만든다.) \\
= \lambda_1 v_1 v_1^T +\lambda_2 v_2 v_2^T +\lambda_3 v_3 v_3^T
$$
$\lambda_i$는  데이터가 주 구성 요소를 따라 얼마나 달라지는 지 나타낸다.

$A$가  $3\times n$행렬이므로 n차원 공간을 3차원 공간으로 줄일 수 있다.

​      $\to$ 차원은 col(A)에 의해 결정되는 것이므로 열벡터 $\mathbf{x}$가 모두 선형 독립이라면 $A$는 n차원 공간에 존재한다.

​            하지만 $(\mathbf{x_i} - \bar{\mathbf{x}})(\mathbf{x_i} - \bar{\mathbf{x}})^T$는 $3\times3$ 이며 3차원공간에 존재하므로 차원을 낮춰 데이터를 압축 할 수 있다.

​           