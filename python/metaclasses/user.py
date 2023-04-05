from library import Base

# Enforce a constrain from derived to base class
assert hasattr(Bae, 'foo'), "you broke it, you fool"

class Derived(Base):
    def bar(self):
        return 'bar'
