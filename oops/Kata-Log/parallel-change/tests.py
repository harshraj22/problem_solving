import unittest
import method
import field


class AuthenticatorTests(unittest.TestCase):

    def test_administrator_is_always_authenticated(self):
        service = method.AuthenticationService()
        adminId = 12345
        self.assertTrue(service.is_authenticated(adminId))

    def test_normal_user_is_not_authenticated_initially(self):
        service = method.AuthenticationService()
        normalUserId = 11111
        self.assertFalse(service.is_authenticated(normalUserId))


class ShoppingCartTests(unittest.TestCase):

    def test_cat_may_just_have_a_single_item(self):
        shoppingCart = field.ShoppingCart()
        shoppingCart.add(10)
        self.assertEqual(1, shoppingCart.number_of_products())

    def test_the_total_price_of_the_cart_is_total_of_its_contents(self):
        shoppingCart = field.ShoppingCart()
        shoppingCart.add(10)
        self.assertEqual(10, shoppingCart.calculate_total_price())

    def test_has_discount_when_contains_at_least_one_premium_item(self):
        shoppingCart = field.ShoppingCart()
        shoppingCart.add(100)
        self.assertTrue(shoppingCart.has_discount())

    def test_doesnt_have_discount_when_all_its_items_are_cheap(self):
        shoppingCart = field.ShoppingCart()
        shoppingCart.add(10)
        self.assertFalse(shoppingCart.has_discount())


if __name__ == "__main__":
    unittest.main()
