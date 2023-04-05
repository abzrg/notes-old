"""
Note

    Recall that the use of a type alias declares two types to be equivalent to
    one another. Doing `Alias = Original` will make the static type checker treat
    Alias as being exactly equivalent to Original in all cases. This is useful
    when you want to simplify complex type signatures.

    In contrast, `NewType` declares one type to be a subtype of another. Doing
    `Derived = NewType('Derived', Original)` will make the static type checker
    treat `Derived` as a subclass of `Original`, which means a value of type
    `Original` cannot be used in places where a value of type `Derived` is
    expected. This is useful when you want to prevent logic errors with minimal
    runtime cost.


Resources

    https://peps.python.org/pep-0484/#newtype-helper-function
"""

from typing import NewType


UserId = NewType('UserId', int)
some_id = UserId(524313)


...


def get_user_name(user_id: UserId) -> str:
    ...

# passes type checking
user_a = get_user_name(UserId(42351))

# fails type checking; an int is not a UserId
user_b = get_user_name(-1)


...


# 'output' is of type 'int', not 'UserId'
output = UserId(23413) + UserId(54341)


...


from typing import NewType

UserId = NewType('UserId', int)

# Fails at runtime and does not pass type checking
class AdminUserId(UserId): pass


...


from typing import NewType

UserId = NewType('UserId', int)

# However, it is possible to create a NewType based on a ‘derived’ NewType:
ProUserId = NewType('ProUserId', UserId)

