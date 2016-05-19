template < typename T >
Forward_list<T>::Forward_list (){
    m_tail = new Node (T(), nullptr);    
    m_head = new Node( T(), m_tail);
    m_size = 0;
}

template < typename T >
Forward_list<T>::~Forward_list(){
    clear();
    delete m_head;
    delete m_tail;
}

template < typename T >
size_type Forward_list<T>::size() const{
    return m_size;
}

template < typename T >
void Forward_list<T>::clear(){
    while ( m_head->next != m_tail ){
            Node *save = m_head->next;
            
            delete [] m_head->next;        
            m_head->next = save->next;
    }
    m_size = 0;
}

template < typename T >
bool Forward_list<T>::empty(){
    return m_size == 0;
}

template < typename T >
void Forward_list<T>::push_back( const T & x ){
   if ( m_head->next == m_tail ){
        push_front(x);
    }
    else{
        Node *aux = m_head;
        
        while ( aux->next != m_tail ){
            aux = aux->next;
        }
        
        Node * newNode = new Node;
        newNode->data = x;
        newNode->next = aux->next;
        aux->next = newNode;
    }
    m_size++;
}

template < typename T >
T Forward_list<T>::pop_back(){
    if ( m_head->next == m_tail ) throw std::out_of_range("[pop_back()]: List size is 0.");
    
    Node *aux = m_head;
    
    while(aux->next->next != m_tail){
        aux = aux->next;
    }

    Node *save = aux->next; // Salvando o último
    
    aux->next = aux->next->next;
    
    auto out = save->data;
    delete save;
    m_size--;
    return out;
}

template < typename T >
const T & Forward_list<T>::back() const{
    Node *aux = m_head;
    while(aux->next != m_tail){
        aux = aux->next;
    }
    return aux->data;
}

template < typename T >
void Forward_list<T>::assign( const T & x ){
    Node *aux = m_head;
    while(aux->next != m_tail){
        aux = aux->next;
        aux->data = x;
    }
}

// Exclusive
template < typename T >
void Forward_list<T>::push_front( const T & x ){
    Node * start;
    try{
        start = new Node;
    }
    catch( const std::bad_alloc & e )
    {
        return;
    }

    start->data = x;
    start->next = m_head->next;
    m_head->next = start;
    m_size++;
}

template < typename T >
T Forward_list<T>::pop_front(){
    if ( m_head->next == m_tail ) throw std::out_of_range("[pop_front()]: List size is 0.");
    Node *save = m_head->next;
    m_head->next = save->next;
    auto out = save->data;
    delete save;
    m_size--;
    return out;
}

template < typename T >
const T & Forward_list<T>::front() const{
    return m_head->next->data;
}