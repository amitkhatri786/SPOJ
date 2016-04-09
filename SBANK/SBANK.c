    #include<stdio.h>
    #include<stdlib.h>
     
     
     
    struct account
    {
          int control;
          int bank_code;
          int owner_id1;
          int owner_id2;
          int owner_id3;
          int owner_id4;
    };
    typedef struct account AC;
    struct tree
    {
          AC account_number;
          int count;
          struct tree *left;
          struct tree *right;
    };
    typedef struct tree NODE;
     
     
    void createtree( NODE **, AC);
    void inorder(NODE *) ;
    void deletetree(NODE **);
     
    main()
    {
            NODE *root=NULL;
            AC ac;
            //short int l=1,i=1;
             int testcase=0;
             int number_of_accounts=0;
            scanf("%d",&testcase); 
            while(testcase--)
            {
                 scanf("%d",&number_of_accounts);
                // i=1;
                 while(number_of_accounts--)
                 {
                     scanf("%d %d %d %d %d %d",&ac.control,&ac.bank_code,&ac.owner_id1,&ac.owner_id2,&ac.owner_id3,&ac.owner_id4);
                     createtree(&root,ac);
                  //   i++;
                 }
          
                inorder(root);
                deletetree(&root);  
                
                if(testcase)
                  printf("\n");
                //l++;
           }
          //`printf("\v");;
    }
     
    void createtree( NODE **root ,AC x )
    {
       NODE *temp=NULL;
       NODE *r=NULL;
     
       if( *root == NULL )
       {
           //printf(" tree is empty need to create node...\n " );
           temp = (NODE *) malloc (sizeof(NODE));
           temp ->  account_number.control = x.control;
           temp ->  account_number.bank_code = x.bank_code;
           temp ->  account_number.owner_id1 = x.owner_id1;
           temp ->  account_number.owner_id2 = x.owner_id2;
           temp ->  account_number.owner_id3 = x.owner_id3;
           temp ->  account_number.owner_id4 = x.owner_id4;
           temp -> count = 1;
           temp -> left = NULL;
           temp -> right = NULL;
           *root = temp;
       }
       else
       {
           if((x.control == (*root)->account_number.control) && (x.bank_code == (*root)-> account_number.bank_code)\
             && (x.owner_id1 == (*root)-> account_number.owner_id1) && (x.owner_id2 == (*root)-> account_number.owner_id2) \
             && (x.owner_id3 == (*root)-> account_number.owner_id3)  && (x.owner_id4 == (*root)-> account_number.owner_id4))
           {
                (*root)-> count = (*root) -> count + 1;
           }
           else
           {
              if( x.control  < (*root) -> account_number.control )  
                    createtree( &((*root) -> left),x );
                else
                    if( x.control  > (*root) -> account_number.control)
                        createtree( &((*root) -> right),x );
                    else
                        if((x.bank_code < (*root)-> account_number.bank_code))
                            createtree( &((*root) -> left),x );
                        else
                            if((x.bank_code > (*root)-> account_number.bank_code)) 
                                 createtree( &((*root) -> right),x );
                            else
                                if((x.owner_id1 < (*root)-> account_number.owner_id1))
                                    createtree( &((*root) -> left),x );
                                else
                                    if((x.owner_id1 > (*root)-> account_number.owner_id1))
                                        createtree( &((*root) -> right),x );
                                    else
                                        if((x.owner_id2 < (*root)-> account_number.owner_id2))
                                            createtree( &((*root) -> left),x );
                                        else
                                            if((x.owner_id2 > (*root)-> account_number.owner_id2))
                                               createtree( &((*root) -> right),x );
                                            else
                                                if((x.owner_id3 < (*root)-> account_number.owner_id3))
                                                    createtree( &((*root) -> left),x );
                                                else
                                                    if((x.owner_id3 > (*root)-> account_number.owner_id3))
                                                     createtree( &((*root) -> right),x );
                                                   else
                                                       if((x.owner_id4 < (*root)-> account_number.owner_id4))
                                                          createtree( &((*root) -> left),x );
                                                       else
                                                           if((x.owner_id4 > (*root)-> account_number.owner_id4))
                                                               createtree( &((*root) -> right),x );
                            
           }
        }
    }
     
     
     
    void inorder( NODE *root )
    {
       if(root == NULL )
           return;
       inorder( root -> left );
       printf("%02d %08d %04d %04d %04d %04d %d\n",root -> account_number.control,root->account_number.bank_code,\
                                           root-> account_number.owner_id1, root-> account_number.owner_id2,\
                                           root-> account_number.owner_id3,root-> account_number.owner_id4,root->count );
       inorder( root -> right );
    }
     
    void deletetree( NODE **root)
    {
        NODE *temp;
        if( *root == NULL )
            return;
        else 
        {   
            deletetree ( &((*root) -> left )); 
            deletetree ( &((*root) -> right )); 
          //  printf("\n%d  ",(*root)->data);
              free ( *root );  
              *root  = NULL;
     
        }   
    }

