#   compiler Laboratory Assignment 1
#   Assembly Language Programming
#   Commented by : Ankit Kumar Gupta (12CS10006)
#   Date:28-07-2014
#   Note : &data[i][j] = data+4*n*i+4*j
#       in this programm n=20 so &data[i][j] = data+80*i+4*j
#        M[%eax] means value at memory location eax

	.file	"p1.c"                                         # source file name
	.section	.rodata                                # read-only data section
	.align 4					       # align with 4-byte boundary
.LC0:                                                          # Label of string - 1st printf
	.string	"Enter the order of the square matrix: "
.LC1:                                                          # Label of string scanf
	.string	"%d"
	.align 4                                                # align with 4-byte boundary
.LC2:								# Label of string - 2nd printf
	.string	"Enter the matrix in row-major order:"
.LC3:								# Label of string - 3rd printf
	.string	"The input matrix is:"
.LC4:								# Label of string - 4th printf
	.string	"%d "
.LC5:								# Label of string - 5th printf
	.string	"In cs order:"
	.text                                                   # Code starts
.globl main                                                     # main is a global name
	.type	main, @function
main:								# Label main:
	pushl	%ebp						# Save old base pointer
	movl	%esp, %ebp					# ebp <-- esp, set new
								# base pointer to current stack pointer
	andl	$-16, %esp					# Adjust to 16-byte boundary
	subl	$1632, %esp					# Create space for the
								# local array 20*20*4 + 2*4 + function calls (1632)

	movl	$.LC0, %eax       				# Move the 1st parameter			                 
	movl	%eax, (%esp)					# 1st parameter to printf
	call	printf						# Call printf() to print
	movl	$.LC1, %eax					# eax <-- string label for scanf 		
	leal	1620(%esp), %edx                                # edx <---- esp+1620   (&n)
	movl	%edx, 4(%esp)                                   # push &n for scanf function parameter to stack
	movl	%eax, (%esp)                                    # push scanf string parameter from eax to stack 
	call	__isoc99_scanf                                  # call scanf
	movl	$.LC2, (%esp)                                   # Push string label parameter to stack for function puts
	call	puts                                            # call puts to print
	movl	$0, 1624(%esp)                                  # set value of [esp+1624]=0 (i=0)                            
	jmp	.L2                                             # jump to L2 (outer for loop)
.L5:                                                            #  inner for Loop
	movl	$0, 1628(%esp)                                  #  M[esp+1628] <--- 0 # j <-- 0
	jmp	.L3                                             # jump to L3
.L4:                                				# inner for Loop
	leal	20(%esp), %ecx        				# ecx <---  esp+20       #  ecx <-- data
	movl	1624(%esp), %edx                                # edx <---- M[esp+1624]  #  edx <-- i
	movl	%edx, %eax                                      # eax <---- edx          #  eax <--  i
	sall	$2, %eax                                        # eax <-- eax << 2  left shift
                                                                # eax <-- 4*i
	addl	%edx, %eax                                      # eax <--   edx + eax 
	                                                        # eax <--   i + 4*i
	sall	$2, %eax                                        # eax <--   4*(i+ 4*i)
	movl	%eax, %edx                                      # edx <--   4*(i+ 4*i)
	movl	1628(%esp), %eax                                # eax <--   M[esp+1628]   # eax <-- j 
	leal	(%edx,%eax), %eax                               # eax <--   edx + eax     # eax <-- 4*(i+4i) + j 
	sall	$2, %eax                                        # eax <--   4*(4*(i+4i)+ j) 
	leal	(%ecx,%eax), %edx                               # edx <--   eax+ecx
	                                                        # edx <--   data + ecx + eax  
	                                                        # edx <--   data+        
	movl	$.LC1, %eax                                     # push scanf string label onto stack 
	movl	%edx, 4(%esp)                                   # M[esp+4] <--- edx
	movl	%eax, (%esp)					# M[esp]   <--- eax
	call	__isoc99_scanf                                  # call to scanf 
	addl	$1, 1628(%esp)                                  # M[esp+1628] <--- M[esp+1628]+1  # j++  
	                                                        
.L3:                                       			# inner for Loop
	movl	1620(%esp), %eax          		        # eax <--- M[esp+1620]  # value of n
	cmpl	%eax, 1628(%esp)           			# compare M[esp+1628] (j) and eax(n) # compare n and j # j-n
	jl	.L4                        			# jump to L4 if (j -n < 0)
	addl	$1, 1624(%esp)             			# increment M(esp+1624) # i++
.L2:                                                            # outer for loop condition checking
	movl	1620(%esp), %eax            			#  eax <---- esp+1620  # value of n
	cmpl	%eax, 1624(%esp)          		        #  compare value at esp+1624 (i) and and value of eax(n)  #(i-n)
	jl	.L5                         			#  goto L5 if (i-n < 0) 
	movl	$.LC3, (%esp)               			#  Push Label of string for 3rd printf onto stack
	call	puts                        			# call to puts()
	movl	$0, 1624(%esp)              			# M[esp+1624] <--- 0  # i  <--- 0
	jmp	.L6                         			# jump to L6 (Loop)
.L9:
	movl	$0, 1628(%esp)              			# M[esp+1628] <--- 0   # j <--- 0
	jmp	.L7                         			# jump to L7
.L8:
	movl	1624(%esp), %edx            			# edx <-- esp+1624   # edx <--- i
	movl	1628(%esp), %ecx            			# ecx <-- esp+1628   # ecx <--- j
	movl	%edx, %eax                 		 	# eax <-- edx(i)  
	sall	$2, %eax                    			# eax <--- 4*eax       # eax <-- 4*i 
	addl	%edx, %eax                  			# eax <--- eax+edx     # eax <-- 4*i +i
	sall	$2, %eax                    			# eax <--- 4*eax       # eax <-- 4*(4*i+j)
	addl	%ecx, %eax                  			# eax <--  ecx + eax   # eax <-- j+ 4*(4*i+j)
	movl	20(%esp,%eax,4), %edx       			# edx <--  M[esp+20+eax*4]  
	                                   		        # edx <--  M[data + 4*(j+ 4*(4*i+j))]  # edx <-- M[i][j]
	movl	$.LC4, %eax                 			# eax <--  # Label of string - 4th printf
	movl	%edx, 4(%esp)               			# esp+4 <-- edx  # for printf function parameter
	movl	%eax, (%esp)                			# esp <-- eax    # for printf function parameter   
	call	printf                      			# call to printf
	addl	$1, 1628(%esp)             			# M[esp+1628] <-- M[esp+1628]+1
	                                   		        # j <-- j+1  
.L7:                 
	movl	1620(%esp), %eax             			# eax <--- M[esp+1620]  # eax <--- n
	cmpl	%eax, 1628(%esp)             			# compare value at esp+1628 (j) and and value of eax  j-n
	jl	.L8			     			#  goto L8 if cmpl sets flag true (inner for Loop) 
	movl	$10, (%esp)                  			# esp < -- 10  
	                                     			# push ASCII code of '\n' (10) onto stack 
	call	putchar                      			# call to putchar
	addl	$1, 1624(%esp)               			# M[esp+1624] <--- M[esp+1624]+1
	                                     			# i <--- i+1
.L6:                                             		# Loop
	movl	1620(%esp), %eax                 		# eax <-- M[esp+1620]  # eax <--- n
	cmpl	%eax, 1624(%esp)                 		#  compare value at esp+1624 (i) and and value of eax  i-n
	jl	.L9			         		#  goto L9 if (i-n < 0) 
	movl	$.LC5, (%esp)                    		# esp <-- Label of string - 5th printf
	call	puts                            		# call puts()
	movl	1620(%esp), %eax                 		# eax <--- esp+1620  # eax <-- n
	leal	20(%esp), %edx                   		# edx <--  esp +20   # edx <-- data 
	movl	%edx, 4(%esp)                    		# M[esp+4] <-- edx   #  push address of data  
	movl	%eax, (%esp)                     		# esp  <-- eax        # push value of n
	call	cs                               		# call to cs 
	movl	$0, %eax                         		# eax <-- 0    # return value 0 
	leave                                    		# esp <-- ebp  # caller stack pointer
                                                                # ebp <-- old ebp (caller base pointer)
	ret                                      		# return control to caller 
	.size	main, .-main     
	.section	.rodata                  		# read-only data section       
.LC6:                                            		# Label of string scanf
	.string	"%d\n"                             
	.text                                    		# code of cs starts 
.globl cs                                        		# cs is global starts 
	.type	cs, @function 
cs:                                              		# label cs 
	pushl	%ebp                              		# push ebp onto stack # save old base pointer
	movl	%esp, %ebp                       		# ebp <-- ebp # ebp <-- esp, new
						   		# base pointer
	subl	$24, %esp                        		# memory for function parameter and computation
	cmpl	$0, 8(%ebp)                      		# compare M[ebp+8] with 0  # compare n and 0 (n-0)
	jne	.L12                             		# jump on not equal (n-1!=0) to L12 
	movl	$10, (%esp)                      		# esp <-- 10 # ASCII code of '\n'
	call	putchar                          		# call to putchar 
	jmp	.L15                             		# jump to L15
.L12:
	cmpl	$1, 8(%ebp)                    			# compare M[ebp+8] and 1 #  compare n and 1 (n-1)
	jne	.L14                           			# jump on not equal (n-1!=0)
	movl	12(%ebp), %eax                 			# eax <-- ebp+12   # eax <-- data
 	movl	(%eax), %edx                   			# edx <-- M[eax]   # edx <-- data[0][0]
	movl	$.LC6, %eax     	       			# Push the string label for scanf onto stack
	movl	%edx, 4(%esp)                  			# M[esp+4] <--- edx (data[0][0]) # function parameter to printf 
	movl	%eax, (%esp)                  	 		# M[esp]   <--  eax # function parameter to printf (format string)      
	call	printf                         			# call to printf
	jmp	.L15                           			# jump to	 L15
.L14:
	movl	$0, 12(%esp)                   			#  M[esp+12] <--- 0   # function parameter to po (const 0)          
	movl	$1, 8(%esp)                    			#  M[esp+8]  <--- 1   # function parameter to po (const 1)
	movl	12(%ebp), %eax                 			#  eax <---   M[ebp+12]   # eax <-- data  
	movl	%eax, 4(%esp)                  			#  M[esp+4]  <--- eax     # function parameter to po (data)
	movl	8(%ebp), %eax                  			# eax <-- ebp+8 # eax <--- n     
	movl	%eax, (%esp)                   			# esp <-- eax    # esp <-- n # function parameter to po (n)       
	call	po                             			# call to po
	movl	12(%ebp), %eax                 			# eax <--- M[ebp+12] # eax  <-- data
	leal	84(%eax), %edx                 			# edx <--  eax+84    # edx <-- data + 84  # edx <-- data[1][1]
	movl	8(%ebp), %eax                  			# eax <--  M[ebp+8]  # eax <--  n
	subl	$2, %eax                       			# eax <-- eax-2    # eax <--- n-2
	movl	%edx, 4(%esp)                  			# M[esp+4] <-- edx # function parameter to cs (int (*)[ORD])(&data[1][1])
	movl	%eax, (%esp)                   			# M[esp]   <-- eax # function parameter to cs (n-2)
	call	cs                             			# call to cs
.L15:
	leave                       				# esp <-- ebp  # caller stack pointer
                                                                # ebp <-- old ebp (caller base pointer)
	ret                                      		# return control to caller
	.size	cs, .-cs
.globl po                             				# po is global function
	.type	po, @function
po:                                   				# po label
	pushl	%ebp                 		 		# save old base pointer
	movl	%esp, %ebp            				# ebp <-- esp, set new
				     	 			# base pointer
	subl	$24, %esp             				# esp <-- esp -24  # memory for local variables,
                                                                # function parameters,computatios
	movl	16(%ebp), %eax        				# eax <-- M[ebp+16]  # eax <-- type  
	cmpl	$2, %eax              				# compare type with 2 (type-2)
	je	.L19                  				# jump on equal (type-2 == 0)
	cmpl	$2, %eax              				# compare type with 2 (type-2)
	jg	.L22                  				# if(type -2 > 0)  jump on greater
	cmpl	$1, %eax             	 			# comapre type with 1 (type-1)
	je	.L18                  				# jump on equal (type-1 ==0)
	jmp	.L30                  				# jump to L30
.L22:
	cmpl	$3, %eax             				# compare type with 3 (type-3) 
	je	.L20                	 			# jump on equal L20 (type-3 ==0)
	cmpl	$4, %eax             				# compare type with 4 (type-4)
	je	.L21                 				# jump on equal L21 (type-4 ==0)
	jmp	.L30		     				# jump to L30
.L18:
	movl	8(%ebp), %eax        				# eax <--n
	subl	$1, %eax             				# eax <-- n-1
	cmpl	20(%ebp), %eax       				# compare  ind and n-1 ((n-1) - ind)
	jne	.L23                    			# jump on not equal to L23 (n-1-ind !=0)
	movl	$0, 12(%esp)            			# function parameter value at(0)
	movl	$2, 8(%esp)            				# function parameter value at(2)
	movl	12(%ebp), %eax         				# eax <-- ebp+12 (data)
	movl	%eax, 4(%esp)          				# function parameter value at(data)
	movl	8(%ebp), %eax            			# eax <-- ebp+8 (n)
	movl	%eax, (%esp)              			# function parameter value at(n)
	call	po                        			# call to po
	jmp	.L30                       			# jump to L30
.L23:
	movl	20(%ebp), %edx             		 	# edx <-- ebp+20 (ind)
	movl	12(%ebp), %eax             			# eax <--- ebp+12 (data)
	movl	(%eax,%edx,4), %edx        		        # edx <-- data+4*ind
	movl	$.LC4, %eax                		  	# eax <-- Label of string - 5th printf
	movl	%edx, 4(%esp)                			# function parameter value at data+4*ind
	movl	%eax, (%esp)                 			# function parameter value at(format string)
	call	printf                       			# call to printf
	movl	20(%ebp), %eax               			# eax <-- ebp+20 (ind)
	addl	$1, %eax                    		 	# eax <-- ind+1
	movl	%eax, 12(%esp)               			# function parameter value at(ind+1)
	movl	$1, 8(%esp)                  			# function parameter value at(1)
	movl	12(%ebp), %eax              		 	# eax  <-- ebp+12 (data)
	movl	%eax, 4(%esp)             	 		# function parameter value at(data)
	movl	8(%ebp), %eax             			# eax <-- ebp+8 (n)
	movl	%eax, (%esp)                 			# function parameter value at(n)
	call	po                            			# call to po
	jmp	.L30                           			# jump to L30
.L19:
	movl	8(%ebp), %eax             			# eax <-- ebp+8  (n) 
	subl	$1, %eax                  			# eax <-- eax-1   (n-1)
	cmpl	20(%ebp), %eax          			# compare eax with ebp+20   # compare n-1 and ind (n-1-ind)
	jne	.L25                      			# if(n-1-ind !=0) jump  
	movl	8(%ebp), %eax             			# eax <-- ebp+8  (n)
	subl	$1, %eax                  			# eax <-- (n-1)
	movl	%eax, 12(%esp)            			# function parameter (n-1) 
	movl	$3, 8(%esp)               			# function parameter (3)
	movl	12(%ebp), %eax           	 		# eax <-- ebp+12 (data)
	movl	%eax, 4(%esp)            			# function parameter (data)
	movl	8(%ebp), %eax             			# eax <-- ebp+8 (n)
	movl	%eax, (%esp)              			# function parameter (n)
	call	po                         			# call to po
	jmp	.L30                        			# jump to L30
.L25:
	movl	20(%ebp), %edx		     			# edx <-- ebp+20  # edx <-- ind
	movl	%edx, %eax              	                # eax <--- ind 
	sall	$2, %eax               		                # eax <-- eax*4    # 4*ind
	addl	%edx, %eax                              	# eax <-- eax+edx   # eax <-- ind+4*ind
	sall	$4, %eax                                	# eax <--  16*(ind+4*ind)
	addl	12(%ebp), %eax                          	# eax <--  16*(ind+4*ind)+ data
	movl	8(%ebp), %edx                           	# edx <--  ebp+8  (n)
	subl	$1, %edx                                	# edx <--  edx-1  (n-1)
	movl	(%eax,%edx,4), %edx                     	# edx <--  eax + edx*4  (16*(ind+4*ind)+ data + 4*(n-1))
                                                                # edx <-- data[ind][n-1]
	movl	$.LC4, %eax                             	# eax <--  Label of string - 5th printf
	movl	%edx, 4(%esp)                           	# M[esp+4] <-- edx  # function parameter (data[ind][n-1]) 
	movl	%eax, (%esp)                           		# esp <-- eax    # function parameter (format string) 
	call	printf                                  	# call to printf()
	movl	20(%ebp), %eax                          	# eax <-- M[ebp+20] (ind)
	addl	$1, %eax                                	# eax <--  ind+1
	movl	%eax, 12(%esp)                          	# function parameter (ind+1)
	movl	$2, 8(%esp)                             	# function parameter (2)
	movl	12(%ebp), %eax                          	# eax <-- ebp+12 (data)
	movl	%eax, 4(%esp)                            	# function parameter (data)
	movl	8(%ebp), %eax                           	# eax    <-- ebp+8
	movl	%eax, (%esp)                            	# function parameter n
	call	po                                       	# call to po
	jmp	.L30                                    	# jump to L30
.L20:
	cmpl	$0, 20(%ebp)                          		# comapre ind with 0
	jne	.L27                                   		# jump on equal
	movl	8(%ebp), %eax                          		# eax <-- ebp+8 (n)
	subl	$1, %eax                               		# eax <-- n-1
	movl	%eax, 12(%esp)                        	 	# function parameter  (n-1)
	movl	$4, 8(%esp)                            		# function parameter  (4)
	movl	12(%ebp), %eax                         		#  eax  <-- ebp+12  (data)
	movl	%eax, 4(%esp)                          		# function parameter  (data)
	movl	8(%ebp), %eax                          		# eax <-- ebp+8   (n)
	movl	%eax, (%esp)                           		# function parameter (n)
	call	po                                     		# call to po
	jmp	.L30                                   		# jump to L30
.L27:
	movl	8(%ebp), %eax                        		# eax  <-- ebp+8 (n)
	leal	-1(%eax), %edx                       		# edx  <-- eax-1 (n-1)
	movl	%edx, %eax                           		# eax  <-- edx   (n-1)
	sall	$2, %eax                            	 	# eax  <-- 4*(n-1)
	addl	%edx, %eax                           		# eax  <-- n-1 + 4*(n-1)
	sall	$4, %eax                             		# eax  <-- 16*(n-1 + 4*(n-1))
	addl	12(%ebp), %eax                       		# eax  <-- ebp+12+ eax
	                                             		# eax  <-- data + 16*(n-1 + 4*(n-1))
	movl	20(%ebp), %edx                       		# edx  <-- M[ebp+20]  (ind)
	movl	(%eax,%edx,4), %edx                  		# edx  <-- eax+edx*4  (data + 16*(n-1 + 4*(n-1))+4*ind)
                                                                # edx  <-- data[n-1][ind]
	movl	$.LC4, %eax                          		# eax  <-- Label of string - 5th printf
	movl	%edx, 4(%esp)                        		# M[esp+4] <-- edx # function parameter 
	movl	%eax, (%esp)                         		# esp <-- eax  # function parameter
	call	printf                               		# call to printf()
	movl	20(%ebp), %eax                      		# eax  <-- ebp+20  (ind)
	subl	$1, %eax                             		# eax   <-- ind-1
	movl	%eax, 12(%esp)                       		# function parameter  (ind-1)
	movl	$3, 8(%esp)                          		# function parameter  (3)
	movl	12(%ebp), %eax                       		# eax <-- ebp+12  (data)
	movl	%eax, 4(%esp)                        		# function parameter (data)
	movl	8(%ebp), %eax                        		# eax <-- ebp+8  (n)
	movl	%eax, (%esp)                         		# function parameter (data) 
	call	po
	jmp	.L30
.L21:
	cmpl	$0, 20(%ebp)		                         # compare ind and 0 
	je	.L31            	                         # jump to L31 on equal
.L29:
	movl	20(%ebp), %edx              		         # edx <-- ebp+20 (ind)
	movl	%edx, %eax                  		         # eax <-- ind
	sall	$2, %eax                                	 # eax <-- 4*ind
	addl	%edx, %eax                           		 # eax <--eax+edx (ind +4*ind)
	sall	$4, %eax                             		 # eax <-- 16*(ind +4*ind)
	addl	12(%ebp), %eax                       	         # eax <-- data+16*(ind +4*ind)
	movl	(%eax), %edx                        		 # edx <-- M[data+16*(ind +4*ind)] # data+80*ind
                                                                 # edx <-- data[ind][0] 
	movl	$.LC4, %eax                          		 # eax   <-- Label of string - 5th printf 
	movl	%edx, 4(%esp)                        		 # function parameter (data[ind][0])
	movl	%eax, (%esp)                         		 # function parameter (format string)
	call	printf 			             		 # call to printf()
	movl	20(%ebp), %eax                       		 # eax <-- ind
	subl	$1, %eax                             		 # eax <-- ind-1
	movl	%eax, 12(%esp)                       		 # function parameter (ind-1) 
	movl	$4, 8(%esp)                          		 # function parameter (4)
	movl	12(%ebp), %eax                       		 # eax <-- ebp+12 (data)
	movl	%eax, 4(%esp)                        		 # function parameter (data)
	movl	8(%ebp), %eax                        		 # eax <-- n
	movl	%eax, (%esp)                         		 # function parameter (n)
	call	po                                   		 # call to po
	nop                                          		 # no operation 
	jmp	.L30                                	 	 # jump to L30
.L31:
	nop                                                      # no operation 
.L30:
	leave              					# esp <-- ebp  # caller stack pointer
                                                                # ebp <-- old ebp (caller base pointer)
	ret                                      		# return control to caller
	.size	po, .-po
	.ident	"GCC: (GNU) 4.4.6 20120305 (Red Hat 4.4.6-4)"
	.section	.note.GNU-stack,"",@progbits
