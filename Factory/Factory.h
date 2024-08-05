

class Product;
class FactoryManager {
public:
    virtual ~FactoryManager();
    static FactoryManager& getInstance(); // 单例模式，工厂管理者

    std::unique_ptr<Product> createProduct(const char type[]);
    void assignStrategy(Product* product, const char type[]); // 策略模式，定义Product对应的Process
};



class Process;
class Product {
public: 
    virtual ~Product();
    virtual void process() const = 0;

    Process* process_;
};

class ProductA : public Product {
public:
    void process() const override;

};
class ProductB : public Product {
public:
    void process() const override;
        
};
class ProductC : public Product {
public:
    void process() const override;
        
};

class ProductCreator {
public:
    virtual ~ProductCreator();
    virtual Product* createProduct() const = 0;
};

class ProductACreator : public ProductCreator{
public:
    Product* createProduct() const override;
};

class ProductBCreator : public ProductCreator{
public:
    Product* createProduct() const override;
};

class ProductCCreator : public ProductCreator{
public:
    Product* createProduct() const override;
};




class Process {
public:
    virtual ~Process();
    virtual void process() const = 0;
};

class Heating : public Process {
public:
    void process() const override;
};
class Cooling : public Process {
public:
    void process() const override;
};
class Mixing : public Process {
public:
    void process() const override;
};

class ProcessCreator {
public:
    virtual ~ProcessCreator();
    virtual Process* createProcess() const = 0;
    
};

class HeatingCreator : public ProcessCreator {
public:
    Process* createProcess() const override;
};

class CoolingCreator : public ProcessCreator {
public:
    Process* createProcess() const override;
};

class MixingCreator : public ProcessCreator {
public:
    Process* createProcess() const override;
};