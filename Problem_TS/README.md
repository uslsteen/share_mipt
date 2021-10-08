# Problem Text Sortion

Tool to sort text in different directions. 

# Build 

Go to project directory and run:


```
mkdir build
cd build/

cmake ..
```

# Usage

From build

```
./Problem_TS <input> <output> algorithm sort_mode
```

- ```<input>  - <path/to/input stream>```

- ```<output> - <path/to/output_stream>```

- ```algorithm:```

            - custom   - m_qsort realisation

            - standart - standart qsort


- ```sort_mode:```

            - forward  - sorting from beginning

            - backward - sorting from ending

# Examples

Let's sort Hamlet in forward direction. 

```./Problem_TS ../exmpls/hamlet.txt ../results/hmlt_fwd_cust.txt custom forward```
